#include"QuickSort.h"

/* 本篇内容将实现：C 语言版顺序存储：快速排序 */


void test_QuickSort() {
#if 1
	printf("============================================================\n");
	printf("整型测试用例：\n");
	int a[] = { 5,3,6,44,8,2 };
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	QuickSort1(&a, 0, size - 1);
	PrintArray1(&a, size);
	QuickSort2(&a, 0, size - 1);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("字符型测试用例（注：需将 typedef int DataType; 改成：typedef char DataType;才可正常）：\n");
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