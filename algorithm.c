#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int original[MAX_SIZE];
int list[MAX_SIZE];
int Destination[MAX_SIZE];
clock_t start, finish, used_time = 0;
int n;

void Sequential_Search(int list[], int len, int target);
void MergeSort(int DataSet[], int StartIndex, int EndIndex);
void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex);
void Swap(int* a, int* b);
int partition(int list[], int left, int right);
void quick_sort(int list[], int left, int right);
void bubble_sort(int list[], int n);
void insertion_sort(int list[], int n);
void CopyArr();
void CalcTime();

void main() {
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)
		original[i] = rand();

	printf("데이터의 개수 : %d\n\n", n);

	CopyArr();
	start = clock();
	printf("순차 탐색 중 ...\n");
	Sequential_Search(list, n, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("삽입 정렬 중 ...\n");
	insertion_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("버블 정렬 중...\n");
	bubble_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("병합 정렬 중...\n");
	MergeSort(list, 0, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("퀵 정렬 중...\n");
	quick_sort(list, 0, n);
	finish = clock();
	CalcTime();
}

void Sequential_Search(int list[], int len, int target) // 순차탐색 
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (target == list[i])
		{
			break;
		}

	}
}

void MergeSort(int DataSet[], int StartIndex, int EndIndex) {
	int MiddleIndex;

	if (EndIndex - StartIndex < 1)
		return;

	MiddleIndex = (StartIndex + EndIndex) / 2;

	MergeSort(DataSet, StartIndex, MiddleIndex);
	MergeSort(DataSet, MiddleIndex + 1, EndIndex);

	Merge(DataSet, StartIndex, MiddleIndex, EndIndex);

}

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex) {
	int i;
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex + 1;
	int DestIndex = 0;

	int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));

	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex) {
		if (DataSet[LeftIndex] < DataSet[RightIndex])
		{
			Destination[DestIndex] = DataSet[LeftIndex];
			LeftIndex++;
		}
		else {
			Destination[DestIndex] = DataSet[RightIndex];
			RightIndex++;
		}
		DestIndex++;
	}

	while (LeftIndex <= MiddleIndex)
		Destination[DestIndex++] = DataSet[LeftIndex++];

	while (RightIndex <= EndIndex)
		Destination[DestIndex++] = DataSet[RightIndex++];

	DestIndex = 0;
	for (i = StartIndex; i <= EndIndex; i++)
	{
		DataSet[i] = Destination[DestIndex++];
	}
	free(Destination);
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int list[], int left, int right) {
	int first = left;
	int pivot = list[first];

	++left;

	while (left <= right) {
		while (list[left] <= pivot && left < right)
			++left;
		while (list[right] > pivot && left <= right)
			--right;
		if (left < right)
			Swap(&list[left], &list[right]);
		else
			break;
	}
	Swap(&list[first], &list[right]);
	return right;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

void bubble_sort(int list[], int n) {
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - (i + 1); j++)
			if (list[j] > list[j + 1]) {
				tmp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = tmp;
			}
	}
}

void insertion_sort(int list[], int n) {
	int i = 0;
	int j = 0;
	int key = 0;
	for (i = 1; i < n; i++) {
		if (list[i - 1] <= list[i])
			continue;
		key = list[i];
		for (j = 0; j < i; j++)
			if (list[j] > key) {
				memmove(&list[j + 1], &list[j], sizeof(list[0]) * (i - j));
				list[j] = key;
				break;
			}
	}
}

void CopyArr() {
	int i;
	for (i = 0; i < n; i++)
		list[i] = original[i];
}

void CalcTime() {
	used_time = finish - start;
	printf("완료!\n소요 시간 : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}