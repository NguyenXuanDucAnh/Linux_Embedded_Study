| Hàm      | Cách truyền tham số      | Có dùng `PATH` không | Có truyền `env` không | Khi nào dùng                                 |
| -------- | ------------------------ | -------------------- | --------------------- | -------------------------------------------- |
| `execl`  | List (`arg1, arg2, ...`) | ❌ Không              | ❌ Không               | Khi biết rõ **đường dẫn đầy đủ**, tham số ít |
| `execlp` | List (`arg1, arg2, ...`) | ✅ Có                 | ❌ Không               | Khi muốn **tự tìm lệnh trong PATH**          |
| `execv`  | Mảng `argv[]`            | ❌ Không              | ❌ Không               | Khi tham số **được tạo động (array)**        |
| `execvp` | Mảng `argv[]`            | ✅ Có                 | ❌ Không               | Phổ biến nhất: **array + PATH**              |
| `execle` | List (`arg1, arg2, ...`) | ❌ Không              | ✅ Có                  | Khi cần **truyền environment riêng**         |


| Hàm      | Prototype                             | Ví dụ                                              |
| -------- | ------------------------------------- | -------------------------------------------------- |
| `execl`  | `execl(path, arg0, arg1, ..., NULL)`  | `execl("/bin/ls", "ls", "-l", NULL);`              |
| `execlp` | `execlp(file, arg0, arg1, ..., NULL)` | `execlp("ls", "ls", "-l", NULL);`                  |
| `execv`  | `execv(path, argv[])`                 | `char *a[]={"ls","-l",NULL}; execv("/bin/ls", a);` |
| `execvp` | `execvp(file, argv[])`                | `char *a[]={"ls","-l",NULL}; execvp("ls", a);`     |
| `execle` | `execle(path, arg0,...,NULL, envp[])` | `execle("/usr/bin/env","env",NULL,env);`           |


| Nếu bạn muốn                | Chọn                         |
| --------------------------- | ---------------------------- |
| Code đơn giản, ít tham số   | `execl`                      |
| Không cần ghi đường dẫn     | `execlp`                     |
| Tham số dạng mảng (dynamic) | `execv`                      |
| Mảng + không cần path       | `execvp` ⭐ (dùng nhiều nhất) |
| Custom environment          | `execle`                     |
