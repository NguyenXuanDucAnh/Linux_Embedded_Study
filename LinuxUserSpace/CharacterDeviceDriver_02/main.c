#include <linux/module.h>      // Thư viện cho module
#include <linux/kernel.h>      // Thư viện cho kernel
#include <linux/fs.h>          // Thư viện cho file operations
#include <linux/uaccess.h>     // Thư viện cho copy_to_user và copy_from_user

#define DEVICE_NAME "hello_character_device" // Tên của device

static int major_number; // Số major của device
static char message[256] = "Hello world\n"; // Thông điệp sẽ được trả về
static short size_of_message; // Kích thước của thông điệp

// Hàm mở device
static int device_open(struct inode *inode, struct file *file) {
    return 0; // Trả về 0 nếu mở thành công
}

// Hàm đóng device
static int device_release(struct inode *inode, struct file *file) {
    return 0; // Trả về 0 nếu đóng thành công
}

// Hàm đọc dữ liệu từ device
static ssize_t device_read(struct file *file, char __user *buffer, size_t len, loff_t *offset) {
    // Kiểm tra nếu đã đọc hết dữ liệu
    if (*offset >= size_of_message) {
        return 0; // Kết thúc file
    }

    // Sao chép dữ liệu từ kernel space sang user space
    if (copy_to_user(buffer, message, size_of_message)) {
        return -EFAULT; // Lỗi nếu sao chép không thành công
    }

    // Cập nhật offset
    *offset += size_of_message;
    return size_of_message; // Trả về kích thước của dữ liệu đã đọc
}

// Cấu trúc file_operations chứa các hàm xử lý
static struct file_operations fops = {
    .open = device_open,      // Hàm mở
    .release = device_release, // Hàm đóng
    .read = device_read,      // Hàm đọc
};

// Hàm khởi tạo module
static int __init hello_world_init(void) {
    // Đăng ký device với kernel và tự động cấp phát số major
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register the device: %d\n", major_number);
        return major_number; // Trả về lỗi nếu đăng ký không thành công
    }
    printk(KERN_INFO "Hello world device registered with major number %d\n", major_number);
    size_of_message = strlen(message); // Tính kích thước của thông điệp
    return 0; // Trả về 0 nếu khởi tạo thành công
}

// Hàm gỡ bỏ module
static void __exit hello_world_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME); // Gỡ bỏ device khỏi kernel
    printk(KERN_INFO "Goodbye from the hello world device!\n"); // Thông báo khi gỡ bỏ
}

// Macro để khởi tạo và gỡ bỏ module
module_init(hello_world_init);
module_exit(hello_world_exit);

// Thông tin về module
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World character device driver");
MODULE_VERSION("0.1");
