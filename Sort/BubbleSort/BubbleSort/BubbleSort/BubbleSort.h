#pragma

#include<stdio.h>

/* 冒泡排序 */
/*
	思路：
		从序列头部开始，相邻元素间依次进行比较，
		而后若满足设定的某种条件就值交换；反复操作
		直至排序完成！

	在冒泡排序中，每次冒泡过程都会使一个最值后置，
	因此，冒泡的序列区间需要随着冒泡次数递减！

	假设：序列大小：size = 10，则索引区间：[0，9]
	若升序处理：
	对于第 1 次冒泡而言：序列中的最大值会后置到：index = 9
	冒泡次数		冒泡对比次数				后置最值的索引
		1				9							9
		2				8							8
		.				.							.
		.				.							.
		10				0							0
	=> 双层for循环制约关系：
		外层：for(int j = 0; j < size ;j ++)
		内层：for(int i = 0; i < size-j ;i++)


	优化问题：由于是通过遍历式的逐次排序，原来的
		排序方式中的外层循环一定会执行序列大小的次数！
		但是，若在排序过程中已有序或原序列就是有序的！
		那么对已有序的序列排序进行逐次冒泡只是在浪费时间，
		故可设置检验指标，若有序则直接结束循环！


	时间复杂度：
	不优化：O(N^2)
	优化：
		最差：O(N^2)
		最优：O(N)

	优化版冒泡排序与插入排序对比：
		1. 若接近有序或部分有序：插入排序更优；
		2. 若已有序，相近；
*/


typedef int DataType;

/* 数值交换函数 */
void Swap(DataType* a, DataType* b);

/* 打印函数 */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* 冒泡排序 */
void BubbleSort1(DataType* array, int size);

/* 优化冒泡排序 */
void BubbleSort2(DataType* array, int size);