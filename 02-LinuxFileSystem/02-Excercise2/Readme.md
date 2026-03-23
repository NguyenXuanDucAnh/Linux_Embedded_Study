# note học được trong quá trình xác minh hành vi của fd2 như sau:
| FD | Ý nghĩa |
| -- | ------- |
| 0  | stdin   |
| 1  | stdout  |
| 2  | stderr  |
nếu ta khởi tạo một fd có giá trị 1 thì khi write nó sẽ ghi ra stdout(giống như cách fd2 đang hoạt động, chỉ khởi tạo và ghi ra luôn không open vào đâu hết. Tuy nhiên do fd2 không khởi tạo giá trị nên nó sinh ra hành vi không xác định - Undefine behavior). 