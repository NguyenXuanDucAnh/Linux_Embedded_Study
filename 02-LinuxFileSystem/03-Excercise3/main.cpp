
/**
 * BT3. Viết một chương trình có só lượng command-line arguments là 5, có dạng như sau:
    $ ./example_program filename num-bytes [r/w] "Hello"
    Trong đó:
        1. example_grogram: Tên file thực thi
        2. filename: Tên file
        3. num-bytes: Số byte muốn read/write
        4. [r/w]: r -> Thực hiện đọc từ  filename và in ra màn hình
                w -> Thực hiện ghi vào filename
        5. "Hello": Nội dung bất kì muốn read/write vào filename

        
 */



#include <iostream>
#include <fcntl.h> // contain system call open()
#include <unistd.h> // contain system call close(), write(), lseek(), read()
#include <cstring>

using namespace std;

#define DEBUG

#define MAX_COMMAND_LINE 5


#define HELP_MENU   "Thứ tự command line:\n"\
                    "1. example_grogram: Tên file thực thi \n" \
                    "2. filename: Tên file \n" \
                    "3. num-bytes: Số byte muốn read/write \n" \
                    "4. [r/w]:  \n"\
                    "\t+ r -> Thực hiện đọc từ  filename và in ra màn hình \n"\
                    "\t+ w -> Thực hiện ghi vào filename \n"\
                    "5. \"Hello\": Nội dung bất kì muốn read/write vào filename\n"
enum {
    EXE_FILE_NAME = 0,
    FILE_TEXT_NAME,
    NUM_BYTE_TO_RW,
    FLAG_R_OR_W,
    CONTENT_TO_WRITE
}; // thứ tự của command line khi đặt trong mảng argv[]
int main (int argc, char * argv[]){

    // kiểm tra nếu nhâp quá linesố lượng command line cho phép
    if (argc > MAX_COMMAND_LINE)
    {
        cout << HELP_MENU;
        cerr << "Command line must be less than " << MAX_COMMAND_LINE << "\n End application~~~"<< endl;
        return -1;
    }

    
    #ifdef DEBUG
        // in ra command line
        cout << "argurment input: \n";

        for (int i=0; i< argc; i++){
            printf ("argument[%d]: %s\n", i, argv[i]);
        }
    #endif 
    char * fileName = argv[FILE_TEXT_NAME];
    int numByteRW = atoi (argv[NUM_BYTE_TO_RW]);
    char * flagRW = argv[FLAG_R_OR_W];

    if (strcmp ("w", flagRW) == 0) // nếu hành động là write thì mới tiến hành thực hiện ghi vào file
    {
        #ifdef DEBUG
            // in ra command line
            cout << "write mode!!!\n";
        #endif 

        // tiến hành mở file để ghi dữ liệu, nêu file chưa tồn tại thì tạo file mới
        int fd_write = open (fileName, O_APPEND | O_CREAT | O_RDWR, 0777);
        if (fd_write < 0)
        {
            perror("Error when open file: ");
            return -1;
        }

        ssize_t sizeWrited = write (fd_write, argv[CONTENT_TO_WRITE], numByteRW);
        close(fd_write);
    }
    else if (strcmp ("r", flagRW) == 0) // nếu hành động là write thì mới tiến hành thực hiện ghi vào file
    {
        #ifdef DEBUG
            // in ra command line
            cout << "read mode!!!\n";
        #endif 

        int fd_read = open (fileName, O_RDWR);
        if (fd_read < 0)
        {
            perror("Error when open file: ");
            return -1;
        }

        char bufRead[1024];
        ssize_t sizeReaded = read (fd_read, bufRead, 1024);
        close(fd_read);

        cout << "content in file read: " << bufRead << endl;
    }
    return 0;
 }