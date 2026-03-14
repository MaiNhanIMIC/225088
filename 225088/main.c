#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include "toan.h"

/**
* @brief tính tổng các phần tử trong mãng
* @param (int*) địa chỉ bất đầu của mãng  
* @param (int) số lượng phần tử của mãng
* 
* @return (int) kết quả của tổng các phần tử trong mãng
*/
int tong_mang(int* dia_chi_mang, int so_luong_phan_tu)
{
	int kq = 0;
	for(int i = 0; i < so_luong_phan_tu; i++)
	{
		//kq += *(dia_chi_mang + i);
		kq += dia_chi_mang[i];
	}

	return kq;
}


void main() 
{
	int mang[] = { 1,2,3 };
	int ret = tong_mang(mang, 3);
}
