#include"MergeSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���鲢���򣨵ݹ�� + �ǵݹ飩 */




void test_MergeSort() {
#if 1
	printf("============================================================\n");
	printf("���Ͳ���������\n");
	int a[] = { 5,3,6,44,8,2,2,64,85,16,48,46,846,4,6843,54,846,16,48,4,1,64,684,6,46 };
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	MergeSort(&a, size);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("�ַ��Ͳ���������ע���轫 typedef int DataType; �ĳɣ�typedef char DataType;�ſ���������\n");
	char b[] = "qwertyuiopasdfghjklzxcvbnm";
	int size = sizeof(b) / sizeof(char);
	PrintArray2(b, size);
	MergeSort(b, size);
	PrintArray2(b, size);
#endif
}

int main() {
	test_MergeSort();

	return 0;
}