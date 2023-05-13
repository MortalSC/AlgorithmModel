#include"QuickSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���������� */


/* ֵ�������� */
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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

/* ˳��洢�������� */
/* ����˵�������������飻�����С */
/* ʱ�临�Ӷȣ� O��N^2��

*/

void QuickSort1(DataType* array, int begin, int end) {
	// �������������Ҫ��һ��ֵ������
	if (begin >= end) return;
	// �˴�ѡ�������һ��ֵΪ���ؼ��ο�ֵ������������Ϊ��ʶ��
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
	// �������������Ҫ��һ��ֵ������
	if (begin >= end) return;
	// Ԥ�������ұ߽����⣬�ó�ʼָ��ָ����������������ⲿ
	int left = begin - 1, right = end + 1;
	// �˴�ѡ�������м�ֵΪ���ؼ��ο�ֵ
	int key = array[left + right >> 1];
	// ���δ���ֻҪ����ָ��δ�����ͳ������н�������
	while (left < right) {
		// do while��������ָ��ָ�����п�ͷ / β��
		// ��ָ������Ѱ�ҵ�һ�����ڹؼ��ο�ֵ��ֵ
		do ++left; while (array[left] > key);
		// ��ָ������Ѱ�ҵ�һ��С�ڹؼ��ο�ֵ��ֵ
		do --right; while (array[right] < key);
		// ע�⣺���ڹ����л��������ָ�롰������������ʽ�����ǰ���ǣ���ָ��һ������ָ������
		if(left < right) Swap(&array[left], &array[right]);
	}
	QuickSort2(array, begin, right), QuickSort2(array, right+1, end);
}