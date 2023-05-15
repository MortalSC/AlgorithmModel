#include"CountSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���������� */


/* ��ӡ���� */
void PrintArray(int* array, int size) {
	printf("array��");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}


/* ˳��洢�������� */
/* ˳��洢�������� */
/* ����˵�������������飻�����С */
void CountSort(int* array, int size) {
	// 1. ���ȱ�����������ѡ����Сֵ�����ֵ��
	int min = array[0], max = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] < min) min = array[i];
		if (array[i] > max) max = array[i];
	}

	// 2. ʹ����Сֵ�����ֵ����һ���������䣻
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL) {
		perror("malloc fail��\n");
		return;
	}
	// ��ʼ�����������е�ֵ
	memset(count, 0, sizeof(int) * range);

	// 3. Ȼ���ٴα��������е�ֵ��ͳ�Ƽ�����
	for (int i = 0; i < size; i++) {
		count[array[i] - min]++;
	}

	// 4. ��д�������ɽ�������������
	int pos = 0;
	for (int i = 0; i < range; i++) {
		while (count[i]--) {
			array[pos++] = i+min;
		}
	}
}