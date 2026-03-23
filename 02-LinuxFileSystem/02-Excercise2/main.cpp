/**
BT2. Sau mỗi lệnh write dưới đây, Cho biết nội dung sẽ được ghi vào file nào, nội dung là gì và giải thích tại sao?
    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd3 = open(file, O_RDWR);
    write(fd1, "Hello,", 6);
    write(fd2, "world", 6);
    lseek(fd2, 0, SEEK_SET);
    write(fd1, "HELLO,", 6);
    write(fd3, "Gidday", 6);
 */

#include <iostream>
#include <fcntl.h> // contain system call open()
#include <unistd.h> // contain system call close(), write(), lseek(), read()


 int main (int argc, char * argv[]){
    int fd1, fd2, fd3;
    const char * pathFile = "fileText.log";
    // S_IRUSR | S_IWUSR hai flag ý nghĩa là quyền đọc cho user và quyền ghi cho user (chỉ user thôi nhé. )
    fd1 = open(pathFile, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // mở file với quyền đọc ghi, nếu file chưa tồn tại thì tạo file. Cờ O_TRUNC là một biến cờ mà khi file đã tồn tại trước khi mở và có nội dung thì file đó sẽ bị xóa hết nội dung (độ dài file bị đưa về 0)
    fd3 = open(pathFile, O_RDWR); // mở file với cờ đọc ghi
    write(fd1, "Hello,", 6); // dùng fd1 ghi vào file đoạn text Hello
    write(fd2, "world", 6); // dùng fd2 ghi vào file. Tuy nhiên, do fd2 không link tới file nào trước đó nên nó sẽ sinh ra một hành vi không xác định (Undefined Behavior). 
    lseek(fd2, 0, SEEK_SET); // khi dùng lseek ở fd 2 thì không có tác dụng gì cả vaf sinh ra Undefined Behavior
    write(fd1, "HELLO,", 6); // ghi vào file tiếp tục nội dung là "HELLO" ở cuối file do con trỏ (cursor) của fd1 được lưu trong open file table đang trỏ tới vị trí sau khi ghi chuỗi "hello," ở trên
    ///. Khi này, nội dung trong file sẽ là: Hello,HELLO, (ta có thể mở file ra xem)

    std::cout<< "nhấn nút bất kỳ để tiếp tục bước cuối cùng:\n";
    getchar();
    write(fd3, "Gidday", 6);
    // ở bước cuối này, do fd3 chưa write vào đâu cả nên cursor của nó trong open file table vẫn trỏ vào vị trí đầu file. Nên khi này chuỗi "Gidday" sẽ ghi đè vào trong file
    // nội dung cuối cùng của file sau bước này sẽ là "GiddayHELLO,". Có thể thấy chuỗi "hello," ở đầu file do fd1 ghi vào đã bị ghi đè bởi fd3

    close (fd1);
    return 0;
 }