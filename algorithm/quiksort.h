#pragma once
#include<bits/stdc++.h>
#include"insertionSort.h"
#include"MergeSort.h"
using namespace std;
template<typename T>
void __quickSort3ways(T arr[], int l, int r)
{
	/*if (l >= r)
		return;*/
	if (r - l <= 15)
	{
		insertionSort2(arr, l, r);
		return;
	}
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int i = l + 1, j = r, lt = l, gt = r + 1;
	while (i < gt)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v)
		{
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else
		{
			i++;
		}
		/*while (i <= r && arr[i] < v)i++;
		while (j >= i && arr[j] > v)j--;
		if (i > j)break;
		swap(arr[i], arr[j]);
		i++;
		j--;//quicksort2*/
	}
	swap(arr[l], arr[lt]);
	//swap(arr[l], arr[j]);//quicksort2
	__quickSort3ways(arr, l, lt - 1);
	__quickSort3ways(arr, gt, r);
}
template<typename T>
void quickSort3ways(T arr[], int n)
{
	srand(time(NULL));
	__quickSort3ways(arr, 0, n - 1);
}