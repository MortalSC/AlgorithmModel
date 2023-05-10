#include"ShellSort.h"

/* 本篇内容将实现：C 语言版顺序存储：插入排序 */


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

/* 写法一：双for循环 + while循环 写法 */
void ShellSort1(DataType* array, int size) {
	int gap = size;									// 希尔处理的间隔步数

	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; ++j) {
			for (int i = j; i < size - gap; i += gap) {
				// 单次希尔插入排序操作
				int end = i;
				DataType temp = array[end + gap];				// 存储等间隔处理的数
				while (end >= 0) {
					if (temp < array[end]) {
						array[end + gap] = array[end];
						end -= gap;
					}
					else break;
				}
				array[end + gap] = temp;
			}
		}
	}
}



/* 写法二：单层for循环 + while循环 写法 */

void ShellSort2(DataType* array, int size) {
	int gap = size;

	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++) {
			// 单次希尔插入排序操作
			int end = i;
			DataType temp = array[end + gap];
			while (end >= 0) {
				if (temp > array[end]) {
					array[end + gap] = array[end];
					end -= gap;
				}
				else break;
			}
			array[end + gap] = temp;
		}
	}
}