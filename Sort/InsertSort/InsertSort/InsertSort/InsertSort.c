#include"InsertSort.h"

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

/* 顺序存储插入排序： */
/* 参数说明：被操作数组；数组大小 */
/* 时间复杂度： O（N^2）
	最优：O（N）
	最差：O（N^2）
*/
void InsertSort(DataType* array, int size) {

	for (int i = 0; i < size - 1; i++) {
		int end = i;							// 用于标识数组中已有序序列的位置：[0，end]已有序，从 end+1 开始待排序
		DataType temp = array[end + 1];			// 标识当前被操作对象（插入对象）

		// 单次插入过程
		while (end >= 0) {
			if (temp < array[end]) {
				array[end + 1] = array[end];
				--end;
			}
			else {
				break;
			}
		}
		array[end + 1] = temp;
	}
}