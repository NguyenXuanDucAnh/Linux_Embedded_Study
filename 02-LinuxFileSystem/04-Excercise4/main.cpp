/**
 * BT4. Tạo file bất kì và ghi một đoạn dữ liệu vào file đó. Thực hiện ghi ra màn hình các thông tin: 
 * Loại file, 
 * tên file, 
 * thời gian chỉnh sửa file lần cuối, 
 * kích thước. 
 * gợi ý: Sử dụng struct stat
 * int stat(const char *restrict path, struct stat *restrict statbuf);
 */

 #include <iostream>
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/stat.h> // chứa systemcall stat
 #include <sys/sysmacros.h> // dùng để đọc major và minor number


 using namespace std;

 int main (int argc, char * argv[]){

    // khai báo struc stat
    struct stat inforFile;

    // mở file, nếu file chưa tồn tại thì tạo file 
    int fd = open ("fileText.log", O_APPEND | O_CREAT | O_RDWR, 0777);
    if (fd < 0)
    {
        perror ("Error when open to file: ");
    }

    // ghi dữ liệu vào file 
    ssize_t sizeWrite = write (fd, "Hoang Sa - Truong Sa la cua Viet Nam\n", sizeof ("Hoang Sa - Truong Sa la cua Viet Nam\n"));
    if (sizeWrite < 0)
    {
        perror ("Error when write to file: ");
    }

    // đóng file
    close (fd);

    // sử dụng stat để truy cập vào và lấy thông tin của file
    int valueRet = stat("fileText.log", &inforFile);
    cout<< "size of file: " << inforFile.st_size << endl;

    // in ra các thông tin của file 
    printf("ID of containing device:  [%x,%x]\n",
                  major(inforFile.st_dev),
                  minor(inforFile.st_dev));

    printf("File type:                ");

    switch (inforFile.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ju\n", (uintmax_t) inforFile.st_ino);

    printf("Mode:                     %jo (octal)\n",
            (uintmax_t) inforFile.st_mode);

    printf("Link count:               %ju\n", (uintmax_t) inforFile.st_nlink);
    printf("Ownership:                UID=%ju   GID=%ju\n",
            (uintmax_t) inforFile.st_uid, (uintmax_t) inforFile.st_gid);

    printf("Preferred I/O block size: %jd bytes\n",
            (intmax_t) inforFile.st_blksize);
    printf("File size:                %jd bytes\n",
            (intmax_t) inforFile.st_size);
    printf("Blocks allocated:         %jd\n",
            (intmax_t) inforFile.st_blocks);

    printf("Last status change:       %s", ctime(&inforFile.st_ctime));
    printf("Last file access:         %s", ctime(&inforFile.st_atime));
    printf("Last file modification:   %s", ctime(&inforFile.st_mtime));

    return 0;
 }