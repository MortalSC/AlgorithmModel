#include"ShellSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���������� */


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

/* д��һ��˫forѭ�� + whileѭ�� д�� */
void ShellSort1(DataType* array, int size) {
	int gap = size;									// ϣ������ļ������

	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; ++j) {
			for (int i = j; i < size - gap; i += gap) {
				// ����ϣ�������������
				int end = i;
				DataType temp = array[end + gap];				// �洢�ȼ���������
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



/* д����������forѭ�� + whileѭ�� д�� */

void ShellSort2(DataType* array, int size) {
	int gap = size;

	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++) {
			// ����ϣ�������������
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