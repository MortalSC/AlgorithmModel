#pragma

/* 本篇内容将实现：C 语言版顺序存储：希尔排序 */
#include<stdio.h>

typedef char DataType;

/* 打印函数 */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* 顺序存储希尔排序： */
/* 参数说明：被操作数组；数组大小 */
/* 写法一：双for循环 + while循环 写法 */
void ShellSort1(DataType* array, int size);

/* 写法二：单层for循环 + while循环 写法 */

void ShellSort2(DataType* array, int size);

