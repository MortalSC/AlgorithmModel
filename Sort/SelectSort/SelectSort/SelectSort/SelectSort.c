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

/* 值交换函数 */
void Swap(DataType* a, DataType* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/* 打印函数 */
void PrintArray1(DataType* array, int size) {
	printf("array：");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void PrintArray2(DataType* array, int size) {
	printf("array：");
	for (int i = 0; i < size; i++)
		printf("%c ", array[i]);
	printf("\n");
}

/* 实现方式：单次处理同时选出最大最小值 */
/* 时间复杂度：O(N^2) */
void SelectSort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//max和min分别代表最大值和最小值的下标
		int max = begin, min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		//如果begin和maxindex重合了，必须调整一下maxindex
		if (begin == max)
		{
			max = min;
		}
		Swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}