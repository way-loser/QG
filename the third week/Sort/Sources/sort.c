#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sort.h"





/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			for (j = i - 1; a[j] > a[0]; j--) {
					a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
	}
	
}



/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */

void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int latter, new, l;
	//latterΪ���������ʼ��newΪ�ϲ��������������,lΪ����������������

	for (latter = mid + 1, new = begin; begin <= mid && latter <= end; new++) {
		if (a[begin] < a[latter])
			temp[new] = a[begin++];
		else
			temp[new] = a[latter++];
	}//�ϲ�ǰ�������н�С��Ԫ��

	if (begin <= mid) {
		//ǰ����û������ͽ�����
		for (l = 0; l <= mid - begin; l++)
			temp[new + l] = a[begin + l];
	}
	if (latter <= end) {
		//������û������ͽ�����
		for (l = 0; l <= end - latter; l++)
			temp[new + l] = a[latter + l];
	}

}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	int mid;//�����е�
	int temp1[MAXSIZE + 1];
	if (begin == end)
		temp[begin] = a[begin];      //�ֺú���Ԫ�ع�λ
	else
	{
		mid = (begin + end) / 2;	//ƽ��
		MergeSort(a, begin, mid, temp1);
		MergeSort(a, mid+1, end, temp1);
		MergeArray(temp1, begin, mid, end, temp);
	}

}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	int pivot;
	if (begin < end) {
		pivot = Partition(a, begin, end);//����ֵ����������λ�ã�Ϊ����Ŀ�ʼֵbegin��
		QuickSort_Recursion(a, begin, pivot - 1);
		QuickSort_Recursion(a, pivot + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size) {

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int* a, int begin, int end) {
	int pivotkey;
	pivotkey = a[begin];
	while (begin < end) {
		while (begin < end && a[end] >= pivotkey)
			end--;
			//��ֵ���������������λ���½��������ƣ�
		swap(a, end, begin);
		//��ֵ������С��ʱ�򣬽������˵���ֵ
		while (begin < end && a[begin] <= pivotkey)
			begin++;
			//ͬ��
		swap(a, end, begin);
	}
	return begin;//������������λ��
}

//���Ž���
void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max) {

}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size) {

}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size) {

}
