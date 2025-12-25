# Đây là code demo một character device in ra hello world dùng monica AI gen
# Nó không có phần đăng ký một major number và minor number thủ công mà đăng ký tự động bằng hàm ***register_chrdev***

Dưới đây là hướng dẫn chi tiết để tạo một character device driver đơn giản in ra "Hello world" bằng ngôn ngữ C, kèm theo Makefile và hướng dẫn cách triển khai và kiểm tra driver trên thiết bị.

### 1. Character Device Driver (hello_world.c)

```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "hello_world_device"

static int major_number;
static char message[256] = "Hello world\n";
static short size_of_message;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t len, loff_t *offset) {
    if (*offset >= size_of_message) {
        return 0; // End of file
    }
    
    if (copy_to_user(buffer, message, size_of_message)) {
        return -EFAULT;
    }
    
    *offset += size_of_message;
    return size_of_message;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
};

static int __init hello_world_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register the device: %d\n", major_number);
        return major_number;
    }
    printk(KERN_INFO "Hello world device registered with major number %d\n", major_number);
    size_of_message = strlen(message);
    return 0;
}

static void __exit hello_world_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Goodbye from the hello world device!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World character device driver");
MODULE_VERSION("0.1");
```

### 2. Makefile

```makefile
obj-m += hello_world.o

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

### 3. Hướng dẫn Deploy và Kiểm tra

#### Bước 1: Biên dịch driver

Mở terminal và điều hướng đến thư mục chứa file `hello_world.c` và `Makefile`. Chạy lệnh sau để biên dịch driver:

```bash
make
```

#### Bước 2: Tải driver vào kernel

Sau khi biên dịch thành công, bạn sẽ có một file module với đuôi `.ko`. Tải module vào kernel bằng lệnh:

```bash
sudo insmod hello_world.ko
```

#### Bước 3: Kiểm tra xem driver đã được tải thành công

Bạn có thể kiểm tra xem driver đã được tải thành công hay chưa bằng lệnh:

```bash
dmesg | tail
```

Lệnh này sẽ hiển thị các thông báo gần đây từ kernel, trong đó bạn sẽ thấy thông báo "Hello world device registered with major number ...".

#### Bước 4: Đọc từ device

Tạo một file device trong `/dev` bằng lệnh:

```bash
sudo mknod /dev/hello_world_device c <major_number> 0
```

Thay `<major_number>` bằng số major mà bạn đã nhận được từ bước kiểm tra ở trên.

Tiếp theo, bạn có thể đọc từ device bằng lệnh:

```bash
cat /dev/hello_world_device
```

Bạn sẽ thấy đầu ra là "Hello world".

#### Bước 5: Gỡ bỏ driver

Khi bạn đã hoàn tất kiểm tra, bạn có thể gỡ bỏ driver bằng lệnh:

```bash
sudo rmmod hello_world
```

### Tóm tắt

- Bạn đã tạo một character device driver đơn giản in ra "Hello world".
- Bạn đã biên dịch, tải driver vào kernel và kiểm tra hoạt động của nó.

Nếu bạn có bất kỳ câu hỏi nào thêm hoặc cần hỗ trợ, hãy cho tôi biết!