#include"CountSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���������� */


void test_CountSort() {

	printf("============================================================\n");
	printf("���Ͳ���������\n");
	int a[30] = { 1,5,8,7,5,2,6,8,4,6,9,5,2,8,5,6,9,9,2,6,8,8,6,9,8,5,6,9,8,5 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(&a, size);
	CountSort(&a, size);
	PrintArray(&a, size);

}

int main() {
	test_CountSort();

	return 0;
}