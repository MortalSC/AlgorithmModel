#pragma

/* 本篇内容将实现：C 语言版顺序存储：归并排序（递归版 + 非递归） */
#include<stdio.h>
#include<stdlib.h>
/*
	算法思想：分治
	实现思路：
		1. 先将原序列，划分为：左右两个子序列；
		2. 若左右子区间都有序，则进行归并！
		3. 归并实现（升序为例）：始终比较两个子序列开头的值，
			取较小值放入一个临时序列【 额外序列空间！ 】，反复操作直至元素完全取完！
		注：当区间中只剩一个值，即是一个有序序列！

	时间复杂度：O（N*logN）
*/

typedef int DataType;

/* 打印函数 */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* 顺序存储归并排序： */
/* 参数说明：被操作数组；序列的左右端点；临时存储序列 */
void _MergeSort(DataType* array, int begin, int end, DataType* temp);
/* 归并排序的辅助函数：用于实现归并过程的空间处理问题 */
void MergeSort(DataType* array, int size);
