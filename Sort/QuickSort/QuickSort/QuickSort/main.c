#include"QuickSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���������� */


void test_QuickSort() {
#if 1
	printf("============================================================\n");
	printf("���Ͳ���������\n");
	int a[] = { 5,3,6,44,8,2 };
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	QuickSort1(&a, 0, size - 1);
	PrintArray1(&a, size);
	QuickSort2(&a, 0, size - 1);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("�ַ��Ͳ���������ע���轫 typedef int DataType; �ĳɣ�typedef char DataType;�ſ���������\n");
	char b[] = "qwertyuiopasdfghjklzxcvbnm";
	int size = sizeof(b) / sizeof(char);
	PrintArray2(b, size);
	QuickSort(b, size);
	PrintArray2(b, size);
#endif
}

int main() {
	test_QuickSort();

	return 0;
}