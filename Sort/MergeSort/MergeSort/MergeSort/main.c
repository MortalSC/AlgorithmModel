#include"MergeSort.h"

/* 本篇内容将实现：C 语言版顺序存储：归并排序（递归版 + 非递归） */




void test_MergeSort() {
#if 1
	printf("============================================================\n");
	printf("整型测试用例：\n");
	int a[] = { 5,3,6,44,8,2,2,64,85,16,48,46,846,4,6843,54,846,16,48,4,1,64,684,6,46 };
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	MergeSort(&a, size);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("字符型测试用例（注：需将 typedef int DataType; 改成：typedef char DataType;才可正常）：\n");
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