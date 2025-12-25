#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "hello_character_device"
#define BUF_LEN 64

static dev_t dev_num;
static struct cdev hello_cdev;
static char message[] = "Hello World from kernel\n";

/* read callback */
static ssize_t hello_read(struct file *file,
                          char __user *buf,
                          size_t len,
                          loff_t *offset)
{
    size_t msg_len = strlen(message);

    if (*offset >= msg_len)
        return 0;

    if (len > msg_len - *offset)
        len = msg_len - *offset;

    if (copy_to_user(buf, message + *offset, len))
        return -EFAULT;

    *offset += len;
    return len;
}

/* file operations */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = hello_read,
};

/* module init */
static int __init hello_init(void)
{
    int ret;

    /* Allocate major + minor dynamically */
    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (ret < 0)
        return ret;

    cdev_init(&hello_cdev, &fops);
    hello_cdev.owner = THIS_MODULE;

    ret = cdev_add(&hello_cdev, dev_num, 1);
    if (ret < 0)
        return ret;

    printk(KERN_INFO "hello_char loaded\n");
    printk(KERN_INFO "Major: %d Minor: %d\n",
           MAJOR(dev_num), MINOR(dev_num));

    return 0;
}

/* module exit */
static void __exit hello_exit(void)
{
    cdev_del(&hello_cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "hello_char unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Hello World Character Device");
