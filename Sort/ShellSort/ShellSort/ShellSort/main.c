#include"ShellSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢��ϣ������ */



void test_ShellSort() {
#if 0
	printf("============================================================\n");
	printf("���Ͳ���������\n");
	int a[] = { 5,3,6,44,8,2,2,64,85,16,48,46,846,4,6843,54,846,16,48,4,1,64,684,6,46 };
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	ShellSort1(&a, size);
	PrintArray1(&a, size);
	ShellSort2(&a, size);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("�ַ��Ͳ���������ע���轫 typedef int DataType; �ĳɣ�typedef char DataType;�ſ���������\n");
	char b[] = "qwertyuiopasdfghjklzxcvbnm";
	int size = sizeof(b) / sizeof(char);
	PrintArray2(b, size);
	ShellSort1(b, size);
	PrintArray2(b, size);
	ShellSort2(b, size);
	PrintArray2(b, size);
#endif
}

int main() {
	test_ShellSort();

	return 0;
}