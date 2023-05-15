#include"MergeSort.h"

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���鲢����ݹ�� */



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


/* ˳��洢�鲢���� */
/* ����˵�������������飻���е����Ҷ˵㣻��ʱ�洢���� */
void _MergeSort(DataType* array, int begin, int end, DataType* temp) {
	// ��������Ԫ�ظ���С�ڵ��� 1 ʱ������С�������У�ֱ�ӷ��أ�
	if (begin >= end) return;

	int mid = (begin + end) >> 1;

	// ���仮�ֹ��̣�[begin��mid]��[mid+1��end]��
	_MergeSort(array, begin, mid, temp);
	_MergeSort(array, mid + 1, end, temp);

	// �鲢����
	// ���ȷֱ��ʶ����������ͷ��Ԫ�أ�����Ԫ�رȽϼ�ȡֵ
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	// �����ʱ���е�ͷ��λ��
	int pos = begin;
	while (begin_1 <= end_1 && begin_2 <= end_2) {
		if (array[begin_1] < array[begin_2])
			temp[pos++] = array[begin_1++];
		else
			temp[pos++] = array[begin_2++];
	}
	// ���ܳ���ĳ����
	while (begin_1 <= end_1) temp[pos++] = array[begin_1++];
	while (begin_2 <= end_2) temp[pos++] = array[begin_2++];

	// ���ݿ���
	memcpy(array + begin, temp + begin, (end - begin + 1) * sizeof(DataType));
}


/* �鲢����ĸ�������������ʵ�ֹ鲢���̵Ŀռ䴦������ */
void MergeSort(DataType* array, int size) {
	// ������ʱ�洢�ռ�
	DataType* temp = (DataType*)malloc(sizeof(DataType)*size);
	// ����ʧ���򷵻���ʾ
	if (temp == NULL) {
		perror("malloc fail��\n");
		return;
	}
	// ���ø�������ʵ�ַ�����鲢
	_MergeSort(array, 0, size - 1, temp);

	// �ͷ��ڴ�ռ�
	free(temp);
}