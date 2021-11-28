#pragma once
#include<bits/stdc++.h>
using namespace std;
int* generateRandomArray(int n, int rangeL, int rangeR)
{
	assert(rangeL <= rangeR);
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}
int* generateNearlyorderArray(int n, int swapTimes)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i;
	srand(time(NULL));
	for (int i = 0; i < swapTimes; i++)
	{
		int posx = rand() % n;
		int posy = rand() % n;
		swap(arr[posx], arr[posy]);
	}
	return arr;
}
int* copyIntArray(int a[], int n)
{
	int* arr = new int[n];
	copy(a, a + n, arr);
	return arr;
}