#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int so_nguyen_t;	// tạo ra kiểu dữ liệu mới, dựa trên cái có sẳn
typedef struct 
{
	int tu;
	int mau;
} phan_so_t;

/**
* @brief tính tích 2 phân số
* @param [IN] A phân số 1
* @param [IN] B phân số 2
* @return phân số
*/
phan_so_t nhan_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t ketqua;
	ketqua.tu = a.tu * b.tu;
	ketqua.mau = a.mau * b.mau;
	return ketqua;
}

/**
* @brief tính tổng 2 phân số
* @param [IN] A phân số 1
* @param [IN] B phân số 2
* @return phân số
*/
phan_so_t cong_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t ketqua;
	ketqua.tu = a.tu*b.mau +  b.tu*a.mau;
	ketqua.mau = a.mau * b.mau;
	return ketqua;
}

/**
* @brief rút gọn phân số
* @param [IN] phân số cần rút gọn
* @return phân số sau khi rút gọn
*/
phan_so_t rut_gon_1(phan_so_t ps)
{
	// min = tử hay mẫu
	int nho_nhat = (ps.tu < ps.mau) ? ps.tu : ps.mau;
	// vòng lập for: i chạy từ min -> 1, NẾU tử chia hết cho i VÀ mẫu chia hết cho i, thì USCLN là i, break khỏi vòng lập
	int USCLN = 1;
	for (int i = nho_nhat; i > 1; i = i - 1)
	{
		if ((ps.tu % i == 0) && (ps.mau % i == 0))
		{
			USCLN = i;
			break;
		}
	}
	// tu của kết quả = tử của ps chia cho USCLN 
	// mẫu của kết quả = mẫu của ps chia cho USCLN
	phan_so_t ket_qua = { ps.tu / USCLN, ps.mau / USCLN };

	// trả kết quả về
	return ket_qua;
}


/**
* @brief rút gọn phân số
* @param [IN/OUT] địa chỉ của phân số cần rút gọn
* @return none
*/
void rut_gon_2(phan_so_t* ps)
{
	int nho_nhat = (ps->tu < ps->mau) ? ps->tu : ps->mau;
	int USCLN = 1;
	for (int i = nho_nhat; i > 1; i = i - 1)
	{
		if ((ps->tu % i == 0) && (ps->mau % i == 0))
		{
			USCLN = i;
			break;
		}
	}
	ps->tu = ps->tu / USCLN;
	ps->mau = ps->mau / USCLN;
}

void main()
{
	// khai báo mảng chưa 5 đối tượng là int và khởi tạo giá trị ban đầu cho 5 đối tượng đó

	// khai báo mảng chứa 5 đối tượng là phân số và khởi tạo giá trị ban đâu cho 5 đối tượng đó
	phan_so_t A[5] = {
		{1,2},
		{3,2},
		{2,3},
		{4,5},
		{1,3}
	};
	// tìm phân số lớn nhất trong mãng
	int vi_tri_lon_nhat = 0;
	float gia_tri_lon_nhat = 0;
	for (int i = 0; i < 5; i++)
	{
		float temp = (float)A[i].tu / (float)A[i].mau;
		if (temp > gia_tri_lon_nhat)
		{
			gia_tri_lon_nhat = temp;
			vi_tri_lon_nhat = i;
		}
	}
	printf("phan so lon nhat la: %d/%d \n", A[vi_tri_lon_nhat].tu, A[vi_tri_lon_nhat].mau);
}

