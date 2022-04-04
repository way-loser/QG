#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sort.h"





/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */

void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int latter, new, l;
	//latter为后数组的起始，new为合并后新数组的排序,l为新数组后续排序序号

	for (latter = mid + 1, new = begin; begin <= mid && latter <= end; new++) {
		if (a[begin] < a[latter])
			temp[new] = a[begin++];
		else
			temp[new] = a[latter++];
	}//合并前后数组中较小的元素

	if (begin <= mid) {
		//前数组没遍历完就结束了
		for (l = 0; l <= mid - begin; l++)
			temp[new + l] = a[begin + l];
	}
	if (latter <= end) {
		//后数组没遍历完就结束了
		for (l = 0; l <= end - latter; l++)
			temp[new + l] = a[latter + l];
	}

}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	int mid;//设置中点
	int temp1[MAXSIZE + 1];
	if (begin == end)
		temp[begin] = a[begin];      //分好后令元素归位
	else
	{
		mid = (begin + end) / 2;	//平分
		MergeSort(a, begin, mid, temp1);
		MergeSort(a, mid+1, end, temp1);
		MergeArray(temp1, begin, mid, end, temp);
	}

}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	int pivot;
	if (begin < end) {
		pivot = Partition(a, begin, end);//返回值是枢轴所在位置（为传入的开始值begin）
		QuickSort_Recursion(a, begin, pivot - 1);
		QuickSort_Recursion(a, pivot + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size) {

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end) {
	int pivotkey;
	pivotkey = a[begin];
	while (begin < end) {
		while (begin < end && a[end] >= pivotkey)
			end--;
			//数值比枢轴大，正常，高位往下降（往左移）
		swap(a, end, begin);
		//数值比枢轴小的时候，交换两端的数值
		while (begin < end && a[begin] <= pivotkey)
			begin++;
			//同理
		swap(a, end, begin);
	}
	return begin;//返回枢轴所在位置
}

//快排交换
void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max) {

}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size) {

}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size) {

}
