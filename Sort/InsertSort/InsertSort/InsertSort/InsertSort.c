#include"InsertSort.h"

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

/* ˳��洢�������� */
/* ����˵�������������飻�����С */
/* ʱ�临�Ӷȣ� O��N^2��
	���ţ�O��N��
	��O��N^2��
*/
void InsertSort(DataType* array, int size) {

	for (int i = 0; i < size - 1; i++) {
		int end = i;							// ���ڱ�ʶ���������������е�λ�ã�[0��end]�����򣬴� end+1 ��ʼ������
		DataType temp = array[end + 1];			// ��ʶ��ǰ���������󣨲������

		// ���β������
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