#pragma

/* 本篇内容将实现：C 语言版顺序存储：插入排序 */
#include<stdio.h>

typedef int DataType;

/* 打印函数 */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* 顺序存储插入排序： */
/* 参数说明：被操作数组；数组大小 */
void InsertSort(DataType* array, int size);
