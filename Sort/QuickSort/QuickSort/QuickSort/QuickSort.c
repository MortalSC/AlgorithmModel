#include"QuickSort.h"

/* 本篇内容将实现：C 语言版顺序存储：快速排序 */


/* 值交换函数 */
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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

/* 顺序存储快速排序： */
/* 参数说明：被操作数组；数组大小 */
/* 时间复杂度： O（N^2）

*/

void QuickSort1(DataType* array, int begin, int end) {
	// 处理的区间至少要有一个值！！！
	if (begin >= end) return;
	// 此处选定区间第一个值为：关键参考值！（且以索引为标识）
	int left = begin, right = end;
	int key_idx = left;

	while (left < right) {
		while (left < right && array[right] >= array[key_idx]) {
			--right;
		}
		while (left < right && array[left] <= array[key_idx]) {
			++left;
		}

		Swap(&array[left], &array[right]);
	}
	Swap(&array[left], &array[key_idx]);
	key_idx = left;

	QuickSort1(array, begin, key_idx - 1);
	QuickSort1(array, key_idx+1, end);
}


void QuickSort2(DataType* array, int begin, int end){
	// 处理的区间至少要有一个值！！！
	if (begin >= end) return;
	// 预处理左右边界问题，让初始指针指向序列左右两侧的外部
	int left = begin - 1, right = end + 1;
	// 此处选择序列中间值为：关键参考值
	int key = array[left + right >> 1];
	// 单次处理：只要左右指针未相遇就持续进行交换处理
	while (left < right) {
		// do while：先让左指针指向序列开头 / 尾部
		// 左指针向右寻找第一个大于关键参考值的值
		do ++left; while (array[left] > key);
		// 右指针向左寻找第一个小于关键参考值的值
		do --right; while (array[right] < key);
		// 注意：由于过程中会出现左右指针“擦肩而过”，故交换的前提是，左指针一定在右指针的左侧
		if(left < right) Swap(&array[left], &array[right]);
	}
	QuickSort2(array, begin, right), QuickSort2(array, right+1, end);
}