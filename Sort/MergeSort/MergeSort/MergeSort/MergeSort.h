#pragma

/* ��ƪ���ݽ�ʵ�֣�C ���԰�˳��洢���鲢���򣨵ݹ�� + �ǵݹ飩 */
#include<stdio.h>
#include<stdlib.h>
/*
	�㷨˼�룺����
	ʵ��˼·��
		1. �Ƚ�ԭ���У�����Ϊ���������������У�
		2. �����������䶼��������й鲢��
		3. �鲢ʵ�֣�����Ϊ������ʼ�ձȽ����������п�ͷ��ֵ��
			ȡ��Сֵ����һ����ʱ���С� �������пռ䣡 ������������ֱ��Ԫ����ȫȡ�꣡
		ע����������ֻʣһ��ֵ������һ���������У�

	ʱ�临�Ӷȣ�O��N*logN��
*/

typedef int DataType;

/* ��ӡ���� */
void PrintArray1(DataType* array, int size);
void PrintArray2(DataType* array, int size);


/* ˳��洢�鲢���� */
/* ����˵�������������飻���е����Ҷ˵㣻��ʱ�洢���� */
void _MergeSort(DataType* array, int begin, int end, DataType* temp);
/* �鲢����ĸ�������������ʵ�ֹ鲢���̵Ŀռ䴦������ */
void MergeSort(DataType* array, int size);
