#pragma once
#include<bits/stdc++.h>
#include"MergeSort.h"
using namespace std;
template<typename T>
void mergeSortBU(T arr[], int n)
{
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
}