#pragma

/* 本篇内容将实现：C 语言版顺序存储：快速排序 */
/*
	核心思路：
		快速排序（升序）就是在被操作序列中任取一个值为 关键参考值！通过一次排序操作
		使得序列左边都小于关键参考值，右边都大于关键参考值！然后反复进行类似操作实现
		排序！

	注意点（实现方式）：
		1. 为了高校，我们可以通过使用“双指针”，分别指向序列的首尾值，并使之向中移动！
		2. 关键步骤：左指针（右移）移动到第一个大于关键参考值的元素对象上，
					再移动右指针（左移），移动到第一个小于关键参考值的元素对象上，
					而后交换左右指针所指向的值，实现核心思路中的：
						序列左边都小于关键参考值，右边都大于关键参考值！
		3. 重复上述第二步骤，使用迭代或递归直到完成排序！
*/
#include<stdio.h>

typedef int DataType;

/* 值交换函数 */
void Swap(int* a, int* b);

/* 打印函数 */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* 顺序存储快速排序： */
/* 参数说明：被操作数组；数组大小 */

void QuickSort1(DataType* array, int start, int end);


void QuickSort2(DataType* array, int start, int end);
