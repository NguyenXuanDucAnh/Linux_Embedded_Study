
# Cách chạy thử ví dụ này:
+ Đơn giản, đây là ví dụ cho sử dụng static library và hiểu về quá trình linker.
+ Tóm gọn để tạo ra một static library ta cần 3 bước:
    + Bước 1: tạo object file từ các file library (file .c .cpp)
    + Bước 2: Tạo các static library (file .a) thông qua dùng ```ar rcs```
    + Bước 3: Link các file .a vào main.cpp ở quá trình linker và sinh ra file thực thi.
+ Các bước sử dụng make file:
    + Nếu chạy ```make linkerLibraryA``` thì main.cpp sẽ được link tới file thư viện mylibraryA.a để sử dụng
    + Nếu chạy ```make linkerLibraryB``` thì main.cpp sẽ được link tới file thư viện mylibraryB.a để sử dụng
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