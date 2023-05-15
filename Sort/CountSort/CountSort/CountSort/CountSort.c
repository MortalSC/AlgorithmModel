#include"CountSort.h"

/* 本篇内容将实现：C 语言版顺序存储：插入排序 */


/* 打印函数 */
void PrintArray(int* array, int size) {
	printf("array：");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}


/* 顺序存储插入排序： */
/* 顺序存储计数排序： */
/* 参数说明：被操作数组；数组大小 */
void CountSort(int* array, int size) {
	// 1. 首先遍历整个序列选出最小值与最大值；
	int min = array[0], max = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] < min) min = array[i];
		if (array[i] > max) max = array[i];
	}

	// 2. 使用最小值与最大值构建一个计数区间；
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL) {
		perror("malloc fail！\n");
		return;
	}
	// 初始化计数序列中的值
	memset(count, 0, sizeof(int) * range);

	// 3. 然后再次遍历序列中的值，统计计数；
	for (int i = 0; i < size; i++) {
		count[array[i] - min]++;
	}

	// 4. 回写排序：生成结果：计数输出；
	int pos = 0;
	for (int i = 0; i < range; i++) {
		while (count[i]--) {
			array[pos++] = i+min;
		}
	}
}