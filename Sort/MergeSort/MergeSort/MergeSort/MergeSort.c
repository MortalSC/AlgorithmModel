#include"MergeSort.h"

/* 本篇内容将实现：C 语言版顺序存储：归并排序递归版 */



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


/* 顺序存储归并排序： */
/* 参数说明：被操作数组；序列的左右端点；临时存储序列 */
void _MergeSort(DataType* array, int begin, int end, DataType* temp) {
	// 当序列中元素个数小于等于 1 时，即最小有序序列，直接返回！
	if (begin >= end) return;

	int mid = (begin + end) >> 1;

	// 区间划分过程：[begin，mid]，[mid+1，end]；
	_MergeSort(array, begin, mid, temp);
	_MergeSort(array, mid + 1, end, temp);

	// 归并过程
	// 首先分别标识左右子序列头部元素，便于元素比较及取值
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	// 标记临时序列的头部位置
	int pos = begin;
	while (begin_1 <= end_1 && begin_2 <= end_2) {
		if (array[begin_1] < array[begin_2])
			temp[pos++] = array[begin_1++];
		else
			temp[pos++] = array[begin_2++];
	}
	// 可能出现某序列
	while (begin_1 <= end_1) temp[pos++] = array[begin_1++];
	while (begin_2 <= end_2) temp[pos++] = array[begin_2++];

	// 数据拷贝
	memcpy(array + begin, temp + begin, (end - begin + 1) * sizeof(DataType));
}


/* 归并排序的辅助函数：用于实现归并过程的空间处理问题 */
void MergeSort(DataType* array, int size) {
	// 申请临时存储空间
	DataType* temp = (DataType*)malloc(sizeof(DataType)*size);
	// 申请失败则返回提示
	if (temp == NULL) {
		perror("malloc fail！\n");
		return;
	}
	// 调用辅助函数实现分治与归并
	_MergeSort(array, 0, size - 1, temp);

	// 释放内存空间
	free(temp);
}