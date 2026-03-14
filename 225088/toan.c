//int cong(int so_nguyen_1, int so_nguyen_2);
//int nhan(int so_nguyen_1, int so_nguyen_2);
#include "toan.h"

/**
* @brief Hàm nhân 2 số nguyên
*
* @param (int) số nguyên 1
* @param (int) số nguyên 2
* @return (int) kết quả của phép nhân 2 số nguyên
*
* @note Không được sử dụng toán tử *, +
*/
int nhan(int so_nguyen_1, int so_nguyen_2)
{
	int kq = 0;
	for (int i = 0; i < so_nguyen_2; i++)
	{
		//kq = kq + so_nguyen_1;
		kq = cong(kq, so_nguyen_1);
	}
	return kq;
}


/**
* @brief Hàm cộng 2 số nguyên
*
* @param (int) số nguyên 1
* @param (int) số nguyên 2
* @return (int) kết quả của phép cộng 2 số nguyên
*/
int cong(int so_nguyen_1, int so_nguyen_2)
{
	int kq;
	kq = so_nguyen_1 + so_nguyen_2;
	return kq;
}