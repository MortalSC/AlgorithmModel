#include"BubbleSort.h"


/* 本篇内容将实现：C 语言版顺序存储：冒泡排序 */


/* 数值交换函数 */
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


/* 冒泡排序 */
void BubbleSort1(DataType* array, int size) {
	// 外层大循环：控制冒泡次数
	for (int j = 0; j < size; ++j) {
		// 单次循环排序操作：
// 此处升序处理：故单次操作会使寻猎最值后置！！！
		// for (int i = 1; i < size; i++) 
		for (int i = 1; i < size-j; i++)

		{
			// 相邻元素大小比较
			if (array[i - 1] > array[i])
				Swap(&array[i - 1], &array[i]);
		}
	}

}


/* 优化冒泡排序 */
/*
	优化问题：由于是通过遍历式的逐次排序，原来的
	排序方式中的外层循环一定会执行序列大小的次数！
	但是，若在排序过程中已有序或原序列就是有序的！
	那么对已有序的序列排序进行逐次冒泡只是在浪费时间，
	故可设置检验指标，若有序则直接结束循环！
*/
void BubbleSort2(DataType* array, int size) {
	// 外层大循环：控制冒泡次数
	for (int j = 0; j < size; j++) {
		int exchange = 1;		// 设置标识：记为有序序
		for (int i = 0; i < size-j; i++) {
			if (array[i - 1] > array[i]) {
				// 若发生交换：说明序列非有序
				exchange = 0;
				Swap(&array[i], &array[i - 1]);
			}
		}
		// 检验是否已有序，有：则推出循环
		if (exchange == 1) break;
	}


}