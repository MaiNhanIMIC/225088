#include <malloc.h>

/* xây dựng thư viện MẢNG CO DÃN
	- tạo mảng với số lượng đối tượng có thể là biến
	- thay đổi kích thức của mảng (tăng, giảm kích thức)
*/

typedef int* mang_co_dan_t;

/**
* brief tạo ra mảng co dãn - int
* param (int) số lượng phần tử trong mảng
* return (int*) địa chỉ bất đầu mảng
*/
mang_co_dan_t tao_mang_co_gian(int soluongphantu)
{
	//int* diachivungnho = malloc(soluongphantu * 4);
	int* diachivungnho = calloc(soluongphantu, 4);
	return diachivungnho;
}

/**
* brief hàm dùng để thay đổi kích thước của mảng
* param (int) số phần tử trong mảng sao khi thay đổi
* param (int*) địa chỉ của mảng co giãn cần thay đổi kích thước
* return (int*) địa chỉ mảng sao khi thay đổi
* note: tạo ra vùng nhớ mới với kích thước mới, sao đó copy dữ liệu ở vùng nhớ củ sang vùng nhớ mới
*/
mang_co_dan_t thay_doi_kich_thuoc_mang(int soluongphantu, mang_co_dan_t mangcogian)
{
	int* diachivungnhomoi = malloc(soluongphantu * 4);
	for (int i = 0; i < soluongphantu; i++) {
		diachivungnhomoi[i] = mangcogian[i];
	}
	free(mangcogian);
	return diachivungnhomoi;
}

/**
* brief hàm dùng để insert một phần tử vào mảng co dãn
* param (int) giá trị của phần tử cần insert
* param (int) vị trí để insert phần tử này vào
* param (int*) địa chỉ của mảng co giãn cần insert thêm phần tử
* param (int) kích thước của mảng co giãn
* return (int*) địa chỉ mảng sao khi thay đổi
* note: tạo ra vùng nhớ mởi có kích thước lớn hơn, copy dữ liệu vào vùng nhớ mới và insert đối tượng này vào
*/
int* them_doi_tuong_vao_mang(int gia_tri_phan_tu, int vi_tri, int* mang_co_gian_cu, int kich_thuoc_cu)
{
	int* vung_nho_moi = malloc((kich_thuoc_cu + 1) * 4);
	for (int i = 0; i < vi_tri; i++)
	{
		vung_nho_moi[i] = mang_co_gian_cu[i];
	}
	vung_nho_moi[vi_tri] = gia_tri_phan_tu;
	for (int i = vi_tri + 1; i < kich_thuoc_cu + 1; i++)
	{
		vung_nho_moi[i] = mang_co_gian_cu[i - 1];
	}
	free(mang_co_gian_cu);
	return vung_nho_moi;
}

/**
* brief hàm dùng để remove một phần tử ra khỏi mảng
* param (int) vị trị của đối tượng cần remove
* param (int) địa chỉ của mảng co giãn cần remove bớt phần tử
* param (int) kích thước của mảng co giãn
* return (int*) địa chỉ mảng sao khi thay đổi
* note: tạo ra vùng nhớ mởi có kích thước nhỏ hơn, copy dữ liệu vào vùng nhớ mới và không copy đổi cần remove vào
*/
int* xoa_phan_tu_cua_mang(int vi_tri, int* mang_co_gian_cu, int kich_thuoc_cu)
{
	int* vung_nho_moi = malloc((kich_thuoc_cu - 1) * 4);
	for (int i = 0; i < vi_tri; i++)
	{
		vung_nho_moi[i] = mang_co_gian_cu[i];
	}
	for (int i = vi_tri; i < kich_thuoc_cu - 1; i++)
	{
		vung_nho_moi[i] = mang_co_gian_cu[i + 1];
	}
	free(mang_co_gian_cu);
	return vung_nho_moi;
}