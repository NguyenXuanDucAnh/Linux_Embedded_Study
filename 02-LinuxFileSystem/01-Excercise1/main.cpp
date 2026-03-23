/**
 * BT1. Viết một chương trình mở một file bất kì và sử dụng cờ O_APPEND, 
 * sau đó thực hiện seek về đầu file rồi ghi một vài dữ  liệu vào file đó. 
 * Dữ liệu sẽ xuất hiện ở vị trí nào của file và tại sao lại như vậy?
 */

#include <iostream>
#include <fcntl.h> // contain system call open()
#include <unistd.h> // contain system call close(), write(), lseek(), read()


 int main (int argc, char * argv[]){
    /* Buoc 1: Open file (if file not exist then create file)*/
    const char * pathFile = "fileText.log";
    int fd = open(pathFile, O_APPEND | O_CREAT | O_RDWR, 0777);
    if (fd < 0){
        perror ("Error when open file: ");
    }

    /* Buoc 2: Lseek to head of file when init file at first time*/
    /* off_t lseek(int fd, off_t offset, int whence); */
    off_t offset = lseek (fd, 0, SEEK_SET);
    if (offset < 0){
        perror ("Error when seek cursor in first time: ");
    }

    /* Buoc 3: Write initiation's content to file */
    char bufWrite[255] = "ADN-Linux-Hoang Sa_Truong Sa La Cua Viet Nam!!!\r\n";
    ssize_t sizeBuf = write(fd, bufWrite, sizeof (bufWrite));
    std::cout << "sizeBuf: " << (ssize_t)sizeBuf << "\tsizeof (buf): " << sizeof (bufWrite) << std::endl;
    if (sizeBuf < 0){
        perror ("Error when write content to file");
    }

    /* Buoc 4: Read file content in first time*/
    /* Buoc 4.1: Truoc khi doc file, can dua con tro ve dau file de co the doc duoc. Ly do la vi khi wirte xong thi con tro nam o cuoi file, khi nay neu doc luon thi se khong doc duoc gi het hoac chi doc duoc ky tu cuoi cung cua file ma thoi. nen bat buoc phai dung lseek dua con tro ve dau file truoc khi muon doc*/
    offset = lseek (fd, 0, SEEK_SET);
    if (offset < 0){
        perror ("Error when seek cursor in first time: ");
    }
    // Buoc 4.2: tien hanh doc file
    char bufRead[1024];
    ssize_t sizeContent = read(fd, bufRead, 1024); // neu nhu count lon hon so byte ma file log dang co, read se chi doc du so byte trong file la dung lai
    if (sizeContent < 0){
        perror ("Error when read file: ");
    }

    std::cout << "sizeContent read: " << sizeContent << std::endl;
    std::cout << "content read 1: " << bufRead << std::endl;
    
    /* Buoc 5: lseek ve dau file sau do ghi noi dung moi vao file theo yeu cau de bai*/
    offset = lseek (fd, 0, SEEK_SET);
    if (offset < 0){
        perror ("Error when seek cursor in first time: ");
    }
    // buoc 5.1: ghi du lieu moi vao file
    sprintf (bufWrite, "%s", "ADN-Linux-Dit_Me_Bon_Xam_Luoc_Hoang_Sa_Truong_Sa_Cua_Viet_Nam!!!\r\n");
    sizeBuf = write(fd, bufWrite, sizeof (bufWrite));
    std::cout << "sizeBuf: " << (ssize_t)sizeBuf << "\tsizeof (buf): " << sizeof (bufWrite) << std::endl;
    if (sizeBuf < 0){
        perror ("Error when write content to file");
    }
    // buoc 5.2: Doc du lieu va check ket qua:
    offset = lseek (fd, 0, SEEK_SET);
    if (offset < 0){
        perror ("Error when seek cursor in first time: ");
    }

    sizeContent = read(fd, bufRead, 1024); // neu nhu count lon hon so byte ma file log dang co, read se chi doc du so byte trong file la dung lai
    if (sizeContent < 0){
        perror ("Error when read file: ");
    }

    std::cout << "sizeContent read: " << sizeContent << std::endl;
    std::cout << "content read 2: " << bufRead << std::endl;
    

    /* close file before exit */
    int resuilt = close (fd);
    if (resuilt < 0){
        perror ("Error when close file: ");
    }
    return 0;
 }