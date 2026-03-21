#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
/* xây dựng thư viện MẢNG CO DÃN 
	- tạo mảng với số lượng đối tượng có thể là biến
	- thay đổi kích thức của mảng (tăng, giảm kích thức)
*/

/**
* brief tạo ra mảng co dãn - int
* param (int) số lượng phần tử trong mảng
* return (int*) địa chỉ bất đầu mảng
*/
int* tao_mang_co_gian(int soluongphantu)
{
	int* diachivungnho = malloc(soluongphantu * 4);
	return diachivungnho;
}


/**
* brief hàm dùng để thay đổi kích thước của mảng
* param (int) số phần tử trong mảng sao khi thay đổi
* param (int*) địa chỉ của mảng co giãn cần thay đổi kích thước
* return (int*) địa chỉ mảng sao khi thay đổi
* note: tạo ra vùng nhớ mới với kích thước mới, sao đó copy dữ liệu ở vùng nhớ củ sang vùng nhớ mới
*/
int* thay_doi_kich_thuoc_mang(int soluongphantu, int* mangcogian) 
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

void main()
{
	// sử dụng mảng co giãn này
	int* mang = tao_mang_co_gian(1);
	mang[0] = 0;
	int kich_thuoc = 1;
	// lưu tất cả các giá trị được nhập từ bàn phím của người dùng, đến khi nào user nhập 0 thì ngừng lại
	int temp = 0;
	int vi_tri = 0;
	do
	{
		printf("vui long nhap gia tri: ");
		scanf("%d", &temp);
		mang = them_doi_tuong_vao_mang(temp, vi_tri, mang, kich_thuoc);
		vi_tri++;
		kich_thuoc++;
	} while (temp != 0);

	for (int i = 0; i < kich_thuoc; i++)
	{
		printf("mang[%d]: %d \n", i, mang[i]);
	}
	// sao đó remove hết tất cả các giá trị lẽ trong mãng
	for (int i = 0; i < kich_thuoc; i++)
	{
		if (mang[i] % 2 == 1)
		{
			mang = xoa_phan_tu_cua_mang(i, mang, kich_thuoc);
			kich_thuoc--;
		}
	}

	for (int i = 0; i < kich_thuoc; i++)
	{
		printf("mang[%d]: %d \n", i, mang[i]);
	}
}
