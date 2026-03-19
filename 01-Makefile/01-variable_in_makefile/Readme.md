
# Biến .PHONY

+ Sử dụng để  khai báo các target này không phải là file thật trên hệ thống. Ví dụ nếu ta có một file trùng với một target trong make (giả sử ta có file rule1 nằm cùng cấp với Makefile). Vậy khi ta nhấn ```make rule1``` thì make sẽ thực thi vào file đó chứ không thực thi target rule1 trong make file vì thế sẽ gây lỗi. Như vậy ta cần có ***.PHONY*** là vì thế.

ví dụ: 
.PHONY: rule1 rule2 rule3

# .SUFFIXES (sẽ bổ sung sau)

# Phép gán thông thường
+ Giống như cách ta gán giá trị cho một biến trong C, phép gán **:=** trong makefile chính là sử dụng cho tác dụng đó. 
+ Một biến được gán bằng phép gán này sẽ luôn mang giá trị đó trừ khi nó bị thay đổi (gán lại ở một nơi khác)
+ Ví dụ: var := "value" và var2 := $(var) thì kể cả var có bị thay đổi giá trị thì var2 vẫn sẽ luôn mang giá trị là "value" cho tớ khi var2 bị gán một phép gán mới.

# Phép gán đệ quy
+ Như trong ví dụ, ta thấy biến var được gán bằng phép gán **=**. Người ta gọi đây là phép gán đệ quy.
+ Phép gán đệ quy là phép gán mà biến được gán sẽ luôn bị thay đổi giá trị nếu giá trị của biến gán bị thay đổi.
+ Ta có thể hiểu đơn giản nó giống như sử dụng con trỏ và trỏ tới một biến trong vùng nhớ. Nếu như biến thay đổi giá trị thì con trỏ khi lấy giá trị cũng sẽ là lấy giá trị bị thay đổi.
+ Ví dụ như biến var1 được gán đệ quy với biến var. Ban đầu, var có giá trị là "value" nên var1 có giá trị là "value". Tuy nhiên, khi var bị gán lại giá trị khác là "changed" thì khi ta ```make rule3`` sẽ thấy var1 có giá trị là changed chứ không phải là "value" nữa.

# Phép gán có điều kiện
+ Phép gán có điều kiện là phép gán được thể hiện bằng dấu **?=**.
+ Nếu như biến được gán trước đó đã được gán một giá trị rôi thì nó sẽ luôn lấy giá trị ban đầu đó và sẽ không bao giờ thay đổi kể cả có gán lại. Nếu biến gán ban đầu là một biến khác thì nó sẽ hiểu đó là phép gán đệ quy.
+ Ví dụ:
    + ví dụ 1: gán giá trị ban đầu
    ```make
    var3 ?= "init varlue"
    var = "ducanhdeptrai"
    var3 = $(var)

    print:
        @echo $(var3)
    ```
    Trong ví dụ này, do var3 đã được gán ?= là "init value" trước rồi nên về sau ta gán var3 với var thì nó sẽ không có hiệu lực nên in ra màn hình sẽ là "init value"

    + ví dụ 2: gán giá trị ban đầu là một biến
    ```make
    var = "ducanhdeptrai"biến
    var3 ?= $(var)
    
    var = "change value"

    print:
        @echo $(var3)
    ```
    Trong ví dụ này, do var3 đã được gán ?= với biến var đầu tiên nên nó là phép gán đệ quy. Do vây khi var bị thay đổi thành "change value" thì var3 cũng sẽ bị thay đổi theo và in ra màn hình giá trị mới.

# Lưu ý quan trọng:
**+ Make không chạy file từ trên xuống theo kiểu “compile rồi execute” như C/C++, mà nó parse toàn bộ file trước, rồi mới thực thi rule.**
+ Ví dụ:
```
.PHONY: rule1 rule2 rule3
 
var := "var"
var3 := "var3"


var1 = $(var)
var2 := $(var)
var3 ?= $(var)

beforeChange:
	@echo "$(var1)"

var := "changed"

afterChange:
	@echo "$(var1)"
```
+ Theo thông thường, ta sẽ nghĩ beforeChange sẽ cho ra kết quả là "var" và afterChange sẽ cho ra kết quả là "changed" vì biến var1 được gán theo kiểu đệ quy. Tuy nhiên:
+ Nếu ta tạo rule như trên, thì khi make rule beforeChange hay afterChange thì kết quả đều sẽ ra như nhau đó là "changed" vì make sẽ đọc toàn bộ file và gán các thứ xong rồi thực thi chứ không thực thi theo kiểu từ trên xuống dưới.

# Quy tắc đặt tên trong Makefile
+ Ta có thể đặt tên theo 3 cách sau:
    + Đặt là Makefile
    + đặt là makefile
    + đặt file có đuôi .mk
+ nếu trong cùng một cấp thư mục có cả 3 thư mục này thì nếu ta gọi ```make``` thì nó sẽ ưu tiên truy cập vào Makefile để xử lý.
+ nếu ta muốn chỉ định make vào file khác không phải file "Makefile" thì ta dùng lệnh sau: ```make -f <tên file> <target>```
+ ví dụ: ta có file abcd.mk và Makefile cùng cấp. Ta muốn build target print1 trong abcd.mk thì ta build như sau: ```make -f abcd.mk print1```

# Sử dụng include
+ giả sử chúng ta chia nhỏ các biến ra thành nhiều makefile hoặc nhiều rule thành nhiều make file khác nhau. Khi này, ta sẽ cần một makefile tổng.
+ Tuy nhiên, các rule hoặc các biến của các makefile khác ta vẫn cần dùng trong makefile tổng tuy nhiên ta không muốn define lại. Vậy thì ta sẽ dùng ***include***.
+ Giống như trong C/C++, nó sẽ đưa toàn bộ rule và biến từ file được include vào file gọi include.
+ Như ví dụ, ta có Makefile và abcd.mk và trong Makefile ta có include abcd.mk. Do ta include ở đầu file nên toàn bộ rule (print1 và print2) sẽ đuọc đặt ở đầu file Makefile, trước tất cả các rule khác. Vì thế nếu ta chỉ gõ ```make``` thì do rule của make là build target đầu tiên trong file nếu chỉ ghi make nên target "print" của abcd.mk được include vào Makefile sẽ được thực thi. Việc vì sao make lại ưu tiên nhảy vào Makefile chứ không phải vào abcd.mk thì xem ở phần **Quy tắc đặt tên trong Makefile** phía bên trên.

# Các biến đặc biệt trong Makefile (Automatic Variables)
## biến $@
- Biến **$@** là biến sử dụng khi ta muốn lấy tên target của rule. Ví dụ:
```make
main.c:
    gcc $@ -o run
```
- Như ta thấy ở ví dụ trên, nếu viết tường minh sẽ là ```gcc main.c -o run``` nhưng do ta dùng $@ nên tên target đã được đưa vào tự động.

## biến $< và biến $^
- Biến này sử dụng để lấy tên của dependence đầu tiên có trong rule. Ví dụ:

```
print: main.c foo.c
    @echo $<
```
- Như có thể thấy, khi chạy rule print thì màn hình sẽ in ra main.c
- Ngược lại, nếu ta dùng biến **$^** thì sẽ như sau:
```
print: main.c foo.c
    @echo $^
```
- khi này, ta sẽ thấy rằng chúng ta sẽ có phần in ra màn hình là main.c và foo.c (tức là toàn bộ các dependence).

## biến %
+ Chúng ta sử dụng **%** khi ta cần biểu thị nhiều file giống nhau. Ví dụ: ta cần tạo ra các file foo.c foo.h, main.c main.h, library.c, library.h. Vậy nếu thông thường ta sẽ làm như sau:
```
all: foo.c main.c library.c foo.h main.h library.h

foo.c:
    touch $@C
main.c:
    touch $@C 
library.c:
    touch $@C

foo.h:
    touch $@C
main.h:
    touch $@C 
library.h:
    touch $@C

```
+ Như có thể thấy, chúng ta phải tạo ra khá nhiều rule tạo file trong khi nó là lặp đi lặp lại. Vậy ta có thể làm như sau:
```
all: foo.c main.c library.c foo.h main.h library.h

%.c:
    touch $@C

%.h:
    touch $@C

```

+ Hiểu đơn giản rằng khi có một rule thao tác với file .c hoặc file .h thì nó sẽ tự động được tạo (do ta đã gọi touch). 