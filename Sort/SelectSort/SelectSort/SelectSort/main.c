#include"SelectSort.h"

/* 本篇内容将实现：C 语言版顺序存储：直接选择排序 */

/* 直接选择排序
	1. 直接选择排序（升序）可以从序列头部开始，遍历选择出最大值，
	由于总是会走到序列尾部，故可以把选出的值后置实现排序；
	2. 基于上述思路，有可优化之处，遍历一边只选一个最值效率偏低，
	实际我们可以通过遍历同时选出最大值与最小值分别前置或后置可
	实现效率提升！

	本篇将对优化后的方式进行实现，以供参考！

	对比！！！
	对于与插入排序的对比！
	分情况：
		1. 若为乱序性高的序列，插入排序可能达到：O(N^2)，但是选择排序还是：O(N^2)；
		2. 若已经接近有序的序列，插入排序可能达到：O(N)，但是选择排序还是：O(N^2)；
*/



void test_SelectSort() {
#if 1
	printf("============================================================\n");
	printf("整型测试用例：\n");
	int a[] = { 5,3,6,44,8,2,2,64,85,16,48,46,846,4,6843,54,846,16,48,4,1,64,684,6,46,1 ,165};
	int size = sizeof(a) / sizeof(int);
	PrintArray1(&a, size);
	SelectSort(&a, size);
	PrintArray1(&a, size);

#else
	printf("============================================================\n");
	printf("字符型测试用例（注：需将 typedef int DataType; 改成：typedef char DataType;才可正常）：\n");
	char b[] = "qwertyuiopasdfghjklzxcvbnm";
	int size = sizeof(b) / sizeof(char);
	PrintArray2(b, size);
	SelectSort(b, size);
	PrintArray2(b, size);
#endif
}

int main() {
	test_SelectSort();

	return 0;
}


