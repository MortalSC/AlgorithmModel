#include"BubbleSort.h"


/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢��ð������ */


/* ��ֵ�������� */
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


/* ð������ */
void BubbleSort1(DataType* array, int size) {
	// ����ѭ��������ð�ݴ���
	for (int j = 0; j < size; ++j) {
		// ����ѭ�����������
// �˴��������ʵ��β�����ʹѰ����ֵ���ã�����
		// for (int i = 1; i < size; i++) 
		for (int i = 1; i < size-j; i++)

		{
			// ����Ԫ�ش�С�Ƚ�
			if (array[i - 1] > array[i])
				Swap(&array[i - 1], &array[i]);
		}
	}

}


/* �Ż�ð������ */
/*
	�Ż����⣺������ͨ������ʽ���������ԭ����
	����ʽ�е����ѭ��һ����ִ�����д�С�Ĵ�����
	���ǣ���������������������ԭ���о�������ģ�
	��ô�����������������������ð��ֻ�����˷�ʱ�䣬
	�ʿ����ü���ָ�꣬��������ֱ�ӽ���ѭ����
*/
void BubbleSort2(DataType* array, int size) {
	// ����ѭ��������ð�ݴ���
	for (int j = 0; j < size; j++) {
		int exchange = 1;		// ���ñ�ʶ����Ϊ������
		for (int i = 0; i < size-j; i++) {
			if (array[i - 1] > array[i]) {
				// ������������˵�����з�����
				exchange = 0;
				Swap(&array[i], &array[i - 1]);
			}
		}
		// �����Ƿ��������У����Ƴ�ѭ��
		if (exchange == 1) break;
	}


}