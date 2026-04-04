#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
* @brief miêu tả xếp loại của học sinh
*/
typedef enum {
	GIOI,			// loại GIỎI có giá trị = 0
	KHA,			// loại KHÁ có giá trị  = 1
	TRUNG_BINH,		// loại TRUNG BÌNH có giá trị = 2
	YEU,			// loại YẾU có giá trị = 3
} loai_t;

/**
* @brief Miêu tả đối tượng là học sinh
* bao gồm:
*	+ tên học sinh
*	+ điểm toán
*	+ điểm văn
*	+ điểm trung
*	+ xếp loại học sinh
*/
typedef struct {
	char ten[32];			// tên của học sinh - chứa tối đa 32 ký tự
	float diem_toan;		// điểm toán của học sinh trên than điểm 10
	float diem_van;			// điểm văn của học sinh trên than điểm 10
	float diem_trung_binh;	// điểm trung bình của học sinh = (điểm toán + điểm văn)/2
	loai_t xep_loai;		// xếp loại dựa vào điểm trung bình của học sinh
} hoc_sinh_t;

#include <string.h>
/**
* @brief Tạo một học sinh
* @param ten - tên của học sinh
* @param dToan - điểm toán của học sinh
* @param dVan - điểm văn của học sinh
* @return trả về đối tượng học sinh
*/
hoc_sinh_t tao_hoc_sinh(char* ten, float dToan, float dVan)
{
	hoc_sinh_t kq = { 0 };
	memcpy(kq.ten, ten, strlen(ten));
	kq.diem_toan = dToan;
	kq.diem_van = dVan;
	kq.diem_trung_binh = (dToan + dVan) / 2;
	if (kq.diem_trung_binh >= 8.0)
		kq.xep_loai = GIOI;
	else if (kq.diem_trung_binh >= 6.5)
		kq.xep_loai = KHA;
	else if (kq.diem_trung_binh >= 5.0)
		kq.xep_loai = TRUNG_BINH;
	else
		kq.xep_loai = YEU;

	return kq;
}

/**
* @brief Tìm học sinh có điểm trung bình cao nhất
* @param ds - danh sách học sinh
* @param sl - số lượng học sinh trong danh sách
* @return học sinh có điểm trung bình cao nhất
*/
hoc_sinh_t tim_hoc_sinh_cao_nhat(hoc_sinh_t* ds, int sl)
{
	hoc_sinh_t hoc_sinh_cao_diem_nhat = { 0 };

	for (int i = 0; i < sl; i++)
	{
		if (hoc_sinh_cao_diem_nhat.diem_trung_binh < ds[i].diem_trung_binh)
			hoc_sinh_cao_diem_nhat = ds[i];
	}

	return hoc_sinh_cao_diem_nhat;
}


void main()
{
	hoc_sinh_t danh_sach[5] = { 0 };
	danh_sach[0] = tao_hoc_sinh("Nguyen Van A", 6, 7);
	danh_sach[1] = tao_hoc_sinh("Nguyen Van B", 8, 7);
	danh_sach[2] = tao_hoc_sinh("Nguyen Van C", 5, 7);
	danh_sach[3] = tao_hoc_sinh("Nguyen Van D", 8, 9);
	danh_sach[4] = tao_hoc_sinh("Nguyen Van E", 8, 8);

	hoc_sinh_t hs = tim_hoc_sinh_cao_nhat(danh_sach, 5);
}

