#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

int main() {
	int i = 0;//计数

	//创建顺序表L
	//List* L = (List*)malloc(sizeof(List));
	//int n = L->length;
	int L[MAXSIZE + 1] = {0,4,3,2,9,1};
	int n = MAXSIZE +1;
	



	for ( i = 0; i < n; i++) {
		//L[i] = rand();
		printf("%d  ", L[i]);
	}
	printf("\n");

	clock_t start = clock();
	//insertSort(L, n);   //运行插入排序函数
	//MergeSort(L, 1, n-1, L);//!!!!!传入的数据n为数组元素总数！！！！！
	QuickSort_Recursion(L, 1, n - 1);

	clock_t diff = clock() - start;
	printf("\n用时%d ms\n", diff);

	//输出
	for (i = 0; i < n; i++) {
		printf("%d  ", L[i]);
	}
	printf("\n");
	return 0;
}
