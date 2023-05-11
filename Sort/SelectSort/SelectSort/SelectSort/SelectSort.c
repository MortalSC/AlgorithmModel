#include"SelectSort.h"


/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢��ֱ��ѡ������ */

/* ֱ��ѡ������
	1. ֱ��ѡ���������򣩿��Դ�����ͷ����ʼ������ѡ������ֵ��
	�������ǻ��ߵ�����β�����ʿ��԰�ѡ����ֵ����ʵ������
	2. ��������˼·���п��Ż�֮��������һ��ֻѡһ����ֵЧ��ƫ�ͣ�
	ʵ�����ǿ���ͨ������ͬʱѡ�����ֵ����Сֵ�ֱ�ǰ�û���ÿ�
	ʵ��Ч��������

	��ƪ�����Ż���ķ�ʽ����ʵ�֣��Թ��ο���

	�Աȣ�����
	�������������ĶԱȣ�
	�������
		1. ��Ϊ�����Ըߵ����У�����������ܴﵽ��O(N^2)������ѡ�������ǣ�O(N^2)��
		2. ���Ѿ��ӽ���������У�����������ܴﵽ��O(N)������ѡ�������ǣ�O(N^2)��
*/

/* ֵ�������� */
void Swap(DataType* a, DataType* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/* ��ӡ���� */
void PrintArray1(DataType* array, int size) {
	printf("array��");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void PrintArray2(DataType* array, int size) {
	printf("array��");
	for (int i = 0; i < size; i++)
		printf("%c ", array[i]);
	printf("\n");
}

/* ʵ�ַ�ʽ�����δ���ͬʱѡ�������Сֵ */
/* ʱ�临�Ӷȣ�O(N^2) */
void SelectSort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//max��min�ֱ�������ֵ����Сֵ���±�
		int max = begin, min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		//���begin��maxindex�غ��ˣ��������һ��maxindex
		if (begin == max)
		{
			max = min;
		}
		Swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}