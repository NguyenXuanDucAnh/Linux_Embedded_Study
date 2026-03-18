
# Biến .PHONY

+ Sử dụng để 

ví dụ: 
.PHONY: rule1 rule2 rule3

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