+ Shared lib cần build qua các bước sau:
    + Bước 1: tạo các file object
    + Bước 2: tạo các file .so bằng các sử dụng cờ -fPIC
    + Bước 3: khi compile chương trình main, link nó vào
    + Bước 4: Để chạy file thực thi, export biến môi trường hoặc copy file .so đó vào thư mục lib của hệ thống
+ Các bước sử dụng make file:
    + Nếu chạy ```make linkerLibraryA``` thì main.cpp sẽ được link tới file thư viện mylibraryA.so để sử dụng
    + Nếu chạy ```make linkerLibraryB``` thì main.cpp sẽ được link tới file thư viện mylibraryB.so để sử dụng
    + trước khi chạy file thực thi, hãy chạy file này trong lần chạy đầu tiên: ```export LD_LIBRARY_PATH=lib:$LD_LIBRARY_PATH```. Nếu vị trí tới các file .so của bạn không phải là lib thì hãy thay lib thành đường dẫn tới folder đặt các file .so của bạn. Hoặc không thì hãy copy file .so vào folder lib của hệ thống, khi này sẽ không cần phải chạy lệnh export này nữa (lưu ý chỉ sử dụng khi library đã ok vào realse)


# Nếu tạo library từ file .c rồi compile ra file .a và sau đó link vào file main.cpp thì trong file header (file .h) phải làm fomat như sau: 

```c
#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
extern "C" {
#endif

void say_hello();

#ifdef __cplusplus
}
#endif

#endif
```

**Nếu không làm theo format này** thì sẽ sinh ra lỗi: ```undefined reference to `say_hello` ``` khi link 