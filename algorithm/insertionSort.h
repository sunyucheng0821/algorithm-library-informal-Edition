//
// Created by liuyubobobo on 14/11/2016.
//

#ifndef MERGESORTIMPLEMENTATIONCOMPARISON2_INSERTIONSORT_H
#define MERGESORTIMPLEMENTATIONCOMPARISON2_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; i++) {

        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }

    return;
}

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort2(T arr[], int l, int r) {

    for (int i = l + 1; i <= r; i++) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }

    return;
}

#endif //MERGESORTIMPLEMENTATIONCOMPARISON2_INSERTIONSORT_H