#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() 
{
	short x = 0x1234;
	char low, high;
	char* px;
	px = &x;


	low = *px;
	high = *(px + 1);

}