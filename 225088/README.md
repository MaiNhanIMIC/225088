# Kiểu dữ liệu trong c
| kiểu dữ liệu | kích thước |
|:---:|:--:|
| void | 0 byte |
| char | 1 byte |
| short | 2 bytes |
| int | 4 bytes |
| long long | 8 bytes |
| float | 4 bytes |
| double | 8 bytes |
- Khai báo biến: đi xin vùng nhớ của hệ điều hành
```c
<kiểu dữ liệu> tên_biến [= khởi tạo giá trị ban đầu]
```
VD:
```c
int x = 10;
char y;
```
- Khai báo 5 biến có kiểu dữ liệu là `int`
```c
int x0, x1, x2, x3, x4;
```
---
# MẢNG - ARRAY
- Cho phép tạo ra nhiều biến cùng một lúc
## 1. Cách khai báo
### cách 1:
```
<kiểu dữ liệu> tên_mảng[<số lượng phần tử trong mảng>] = {giá trị ban đầu của từng phần tử};
```
VD: khai báo mảng để chứ 5 phần tử, mỗi phần tử là `int`
```c
int arr[5] = {2,1,4,5,6};
```
*** chú ý: `số lượng phần tử trong mảng` không được phép là một biến, phải là một con số
```c
int n = 5;
int arr[n] = {1,2,3,4,5}; // sai
```
- Khai báo arr bao gồm 5000 đối tượng `char` có giá trị ban đầu bằng 0
```c
char arr[5000] = {0};
```
### cách 2:
```c
<kiểu dữ liệu> tên_mảng[] = {<giá trị khởi tạo ban đầu cho từng phần tử>};
```
*** chú ý: `số lượng phần tử trong mảng` được bỏ trống, lúc này số lượng phần tử trong mảng sẽ được quyết định bởi số lượng phần tử được khởi tạo ban đầu
VD: khai báo 5 phần tử `int`
```c
int arr[] = {2,3,45,6,4};
```
- ta thấy `{2,3,45,6,4}` có 5 đối tượng --> arr tự động được khai báo với 5 phần tử
- Khai báo arr bao gồm 5000 đối tượng `char` có giá trị ban đầu bằng 0
```c
char arr[] = {0}; // ở cách 2 không làm được, ở đây nó chỉ hiểu arr có 1 đối tượng
```
## 2. Sử dụng mảng đã được khai báo
VD: 
```c
int arr[5] = {0}; // khai báo 1 mảng 5 đối tượng int
arr[2] = 10;	  // gán arr[2] = 10
arr[3] = 23;
arr[1] = arr[2] + arr[3];
printf("arr o vi tri 1 = %d \n", arr[1]);
```
- ở khai báo trên ta có một arr 5 đối tượng là int
- mảng cho phép tạo ra nhiều biến, ta thấy khai báo trên tạo ra các biến:
	+ `arr[0]`, `arr[1]`, `arr[2]`, `arr[3]`, `arr[4]`
- Ta có một mảng như sao:
	```c
	int arr[5] = {1,2,3,4,5};
	```
	+ mảng bao gồm 5 đối tượng, mỗi đối tượng là `int`
	+ `arr[0]` trả về giá trị --> 1, arr[0] có kiểu dữ liệu `int`
	+ `arr[3]` trả về giá trị --> 4, arr[3] có kiểu dữ liệu `int`
	+ `&arr[0]` trả về --> địa chỉ của arr[0]
	+ `&arr[3]` trả về --> địa chỉ của arr[3]
	+ `arr` trả về --> &arr[0]: ĐỊA CHỈ BẤT ĐẦU CỦA MẢNG
	+ `sizeof(arr)` trả về --> 20 (5 đối tượng mỗi đối tượng là int (4 bytes))
	+ `sizeof(arr[0])` trả về --> 4
	+ để lấy số lượng phần tử của `arr`:
	```c
		int n = sizeof(arr)/sizeof(arr[0]);
	```
	*** CHÚ Ý: `TÊN của array` đại diện cho địa chỉ bất đầu của array

## 3. Thực hành
- **Bài 1**: Viết chương trình tính tổng của mảng 5 phần tử
	+ giá trị của 5 phần tử này được nhập từ bàn phím
```c
void main()
{
	// khai báo mảng 5 đối tượng int
	int arr[5] = {0};
	int sum = 0;
	int n = sizeof(arr)/sizeof(arr[0])

	for(int i = 0; i < n; i++)
	{
		printf("nhap gia tri arr[%d]: ", i);
		scanf("%d", &arr[i]);
		sum += arr[i]; // sum = sum + arr[0];
	}
	printf("==> tong mang: %d \n", sum);
}

```
- Chỉ tính tổng của các đối tượng có giá trị LẺ
	+ chia lấy dư (%) cho 2 nếu bằng 1 là số LẺ
- **Bài 2**:  in các giá trị của mảng, sao đó đảo ngược mảng
	+ VD: mảng {1,2,3,4,5} sao khi đảo ngược sẽ là {5,4,3,2,1}
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() 
{
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		printf("nhap gia tri cho arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}

	printf("{");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("} \n");


	for (int i = 0; i < 3; i++)
	{
		int temp = arr[i];
		arr[i] = arr[5 - 1 - i];
		arr[5 - 1 - i] = temp;
	}

	printf("{");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("} \n");
}
```
---
# CON TRỎ - POINTER
## Con trỏ là gì?
- Con trỏ là ***biến*** dùng để lưu địa chỉ của một đối tượng
	+ kích thước con trỏ: không phụ thuộc vào kiểu dữ liệu, mà nó sẽ phụ thuộc vào nền tản đang hoạt động
		+ VD: 
			+ đang hoạt động ở x86 thì tất cả các con trỏ (char*, int*, long long*, ...) điều có kích thước là 4 byte
			+ đang hoạt động ở x64 có kích thước là 8 bytes
## Khai báo 1 con trỏ:
```
<kiểu dữ liệu>* tên_con_trỏ [= giá trị khởi tạo ban đầu];
```
- VD:
	```
	int x = 10;	// khai báo biến x để lưu số 10
	int* px;	// khai báo con trỏ px để lưu địa chỉ của biến x
	px = &x;
	 ```
	- `int* px;` khai báo 1 con trỏ để lưu địa chỉ của đối tượng `int`
- VD:
	```
	char x = 10;
	char* px;
	px = &x;
	```
	- `char* px;` khai báo 1 con trỏ để lưu địa chỉ của đối tượng `char`
## Cách sử dụng con trỏ
```
int x = 10;	// khai báo biên x để chứa giá trị 10
int* px;	// khai báo con trỏ px
```
### công dụng 1: dùng để chứa địa chỉ của một đối tượng
```
px = &x;
```
### Công dụng 2: truy cập tới địa chỉ được lưu trong con trỏ
```
*px = 20;
```
- kiểu dữ liệu của con trỏ không thể hiện kích thước của con trỏ mà nó thể hiện KHẢ NÂNG TRUY CẬP của con trỏ
## Toán tử CỘNG cho con trỏ
- toán tử cộng của biến bình thường
```c
int x = 10;
x + 1 --> 11

char y = 10;
y + 1 --> 11
```
- toán tử cộng cho con trỏ
```c
char* px = 0x1000;
px + 1 --> 0x1001

int* py = 0x1000;
py + 1 --> 0x1004
```

## Mối liên hệ giữa CON TRỎ và MẢNG
```c
int arr[3] = {1,2,3};
```
- `arr[0]` --> trả về 1, kiểu dữ liệu là `int`
- `arr[1]` --> trả về 2, kiểu dữ liệu là `int`
- `&arr[0]` --> trả về địa chỉ của `arr[0]`
- `arr` (tên của mảng) --> đại diện *địa chỉ* bắt đầu của mảng tương đương với `&arr[0]` --> kiểu dữ liệu là `int*`
- do `arr` đại diện cho ĐỊA CHỈ của mảng nên ta có
	+ `*(arr + 0)` tương đương với `arr[0]`
	+ `*(arr + 1)` tương đương với `arr[1]`
	+ `*(arr + 2)` tương đương với `arr[2]`

---
# STRING - CHUỖI KÝ TỰ
## Ký tự
- trong máy tính sẽ sử dụng bảng mã ASCII để lưu một ký tự
	+ VD: để lưu ký tự 'a' máy tính sẽ lưu 01100001 <-> 97 --> việc lưu 'a' với số 97 là như nhau trong máy tính
	
	```c
	char x;
	x = 0x61;
	x = 0b01100001;
	x = 97;
	x = 'a';
	```
- Để thể hiện 1 ký tự trong lập trình c thì chúng ta sử dụng dấu `'`
## String - Chuỗi ký tự
### Khai báo chuỗi - cách 1
- Chuỗi ký tự (còn gọi là chuỗi/string) bao gồm nhiều ký tự và ký tự kết thúc chuỗi có giá trị 0
```c
// khai báo chuỗi "hello"
char arr[] = {'h', 'e', 'l', 'l', 'o', 0};

```
- Để đơn giản hóa việc khai báo chuỗi. Ngôn ngữ C cho phép chúng ta khai báo:
```c
char arr[] = "hello";
```
- bản chất khai báo trên giống như khai báo một array để chứa nhiều đối tượng là ký tự
- VD: tìm số lượng phần tử của chuỗi
```c
void main()
{
	char str[] = "hello";
	int i = 0;
	while(str[i] != 0)
	{
		i++;
	}
	printf("so luong ky tu: %d \n", i);
}
```
- Sử dụng `scanf` để nhập giá trị cho chuỗi
```
void main()
{
	// khai báo vùng nhớ để chứa chuỗi được scan từ bàn phim
	char str[100] = {0};
	scanf("%s", str);
```
- chú ý:
	- `scanf("%s", str)` chỉ scan được string không có `space`
	- sử dụng `scanf("%[^\n]%*c", str)` để scan được string có chứa `space`
### Khai báo chuỗi - cách 2
- `"hello"` - chuỗi được chứa trong cập dấu `"` (nháy kép) 
	- nó sẽ trả về địa chỉ bắt đầu của một chuỗi 
	- chuỗi này được cấp phát trong vùng READ ONLY
#### Khai báo chuỗi
```
char* str = "hello";
str[0] = 'H'; // bị OS chặn --> lỗi
```
- cách khai báo 1:
```c
char str[] = "hello";
str[0] = 'H'; // không bị lỗi giống như cách 2
```
### Bài tập:
#### Bài 1: 
Viết chương trình chuyển chuỗi thường thành chuỗi in hoa
	VD: "hello 137484 ^*&^ World" -->"HELLO 137484 ^*&^ WORLD"
#### Bài 2:
Viết chương trình đảo ngược chuỗi
	VD: "hello" --> "olleh"
#### Bài 3:
Viết chương trình kiểm tra chuỗi đó có phải là palindrome không
- palindrome: là đọc xuôi và ngược như nhau
- VD:
	- "hello": không phải là palindrome
	- "level": là palindrome
#### Bài 4: 
Viết chương trình điếm số từ trong chuỗi
	VD: "lap  trinh   c" --> có 3 từ (dự vào ký tự `space`)
#### Bài 5:
Viết chương trình xóa `space` ra khỏi chuỗi
VD: "hello    world" --> "helloworld"
#### Bài 6:
Viết chương trình in hoa chữ cái đầu tiên của từ
VD: "hello world" --> "Hello World"

---
# HÀM - FUNCTION
- Khi làm việc với hàm cần chú ý:
	+ Chức nâng của hàm
	+ Input của hàm
	+ Output của hàm
## Xây dựng hàm
- kiểu dữ liệu
	+ void - 0 byte - void*
	+ char - 1 byte - char*
	+ short - 2 byte - short*
	+ int - 4 byte - int*
	+ long long - 8 byte - long long*
	+ float - 4 byte - float*
	+ double - 8 byte - double*
```c
<kiểu dữ liệu output> ten_ham(<các biến miêu tả input>)
{
	// nội dung của hàm

	return ketqua;
}
```
ví dụ: xây dựng hàm kiểm tra một số nguyên là chẳn hay lẻ
- chức nâng của hàm: hàm này dùng để kiểm tra số nguyên là chẳn hay lẻ
- input: int so_nguyen
- output: quy định 0 là chẳn, 1 là lẻ
```
char kiem_tra_chan_le(int so_nguyen)
{
	char ketqua = 0;
	if(so_nguyen % 2 == 0)
		ketqua = 1;
	else
		ketqua = 0;
	return ketqua;
}
```
## Sử dụng hàm
```c
void main()
{
	int x = 10;
	char chan_le = kiem_tra_chan_le(x);
	if(chan_le == 0)
		printf("x la so chan \n");
	else
		printf("x la so le \n");
}
```
---
# CẤP PHÁT ĐỘNG

- Khai báo một mảng, bao gồm 10 đối tượng `int`
```
int arr1[10];
```
- Số lượng đối tượng phải là một con số, không được phép là biến
- `arr1` không thể thay đổi kích thước của mảng
- Không được phép:
```
int kich_thuoc = 10;
int arr1[kich_thuoc];
```
## Sử dụng hàm `malloc` hoặc `calloc`
- Chủ động cấp phát vùng nhớ
- `malloc`
	+ input: (int) số byte cần cấp phát
	+ output: (void*) *ĐỊA CHỈ* vùng nhớ vừa được cấp phát
	```
	int kich_thuoc = 10;
	char* px = malloc(kich_thuoc);
	*px = 20;
	px[0] = 20;
	
	*(px+1) = 21;
	px[1] = 21;
	```
- `malloc`: khi sử dụng hàm này để cấp phát memory, OS sẽ lấy memory ở vùng nhớ HEAP để cấp phát
- vùng nhớ sẽ tồn tại ĐẾN KHI NÀO được giải phóng bằng cách sử dụng hàm `free`