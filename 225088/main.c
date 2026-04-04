#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/**
* @brief miêu tả một node trong linked list
* chứa:
*	+ địa chỉ của node tiếp theo
*	+ giá trị 
*/
typedef struct {
	void* next_node_addr;	// địa chỉ của node tiếp theo
	int val;				// chứa giá trị của node hiện tại
} node_t;


/**
* @brief miêu tả một đối tượng là linked list
* chứa:
*	+ địa chỉ của node đầu tiên
*	+ số lượng node
*/
typedef struct {
	node_t* root;	// địa chỉ của node đầu tiên (gốc)
	int node_num;	// số lượng node trong linked list
} linked_list_t;
#include <malloc.h>
/**
* @brief khởi tạo một đối tượng linked list với 1 node
* @param [IN] val - giá trị của node đầu tiên
* @param [OUT] pll - địa chỉ của đối tượng linked list sao khi được tạo
* @return NONE
*/
void linked_list_create(int val, linked_list_t* pll)
{
	// sử dụng cấp phát động. sử dụng hàm malloc or calloc để cấp phát vùng nhớ cho node đầu tiên
	node_t* node = malloc(8);
	// gán next_node_addr = 0 và val (của node) = val (của input)
	node->next_node_addr = NULL;
	node->val = val;

	// gán root của (pll) bằng địa chỉ của node được tạo bởi malloc or calloc
	pll->root = node;
	// gán node_num = 1
	pll->node_num = 1;
}

/**
* @brief Thêm một node vào cuối linked list
* @param [INT] val - giá trị của node cuối
* @param [OUT] pll - địa chỉ của đối tượng linked list cần thêm node
* @return NONE
*/
void linked_list_add(int val, linked_list_t* pll)
{
	// sử dụng cấp phát động. sử dụng hàm malloc or calloc để cấp phát vùng nhớ cho node mới
	node_t* node = malloc(sizeof(node_t));
	// gán next_node_addr = 0 và val (của node) = val (của input)
	node->next_node_addr = NULL;
	node->val = val;
	// ta có root của pll và node_num của pll --> tìm tới node cuối của linked_list này --> gán next_node_addr = node vừa tạo ra ở trên
	node_t* lastest_node = pll->root;
	for (int i = 0; i < pll->node_num - 1; i++)
	{
		lastest_node = lastest_node->next_node_addr;
	}
	lastest_node->next_node_addr = node;
	// tăng node_num lên 1
	pll->node_num++;
}

/**
* @brief xóa một node ở vị trí index trong linked list
* @param [INT] index - vị trí node cần xóa
* @param [OUT] pll - địa chỉ của đối tượng linked list cần thêm node
* @return NONE
*/


/**
* @brief lấy giá trị của một node trong linked list
* @param [INT] index - vị trí của node cần lấy giá trị
* @param [OUT] pll - địa chỉ của đối tượng linked list cần thêm node
* @return giá trị của node ở vị trí index
*/

void main()
{
	linked_list_t ll;
	linked_list_create(1, &ll);
	linked_list_add(2, &ll);
	linked_list_add(3, &ll);
	linked_list_add(4, &ll);
	linked_list_add(5, &ll);
	linked_list_add(6, &ll);


	printf("gia tri cua ll o vi tri 3: %d", linked_list_get(3, &ll));
}

