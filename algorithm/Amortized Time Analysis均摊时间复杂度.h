//put your code here
#pragma once
#include<iostream>
using namespace std;
template<typename T>
class MyVector
{
private:
    T* data;
    int capacity;
    int size;
    //O(n)
    void resize(int newCapcity)
    {
        assert(newCapcity >= size);
        T* newData = new T[newCapcity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapcity;
    }
public:
    MyVector()
    {
        capacity = 10;
        size = 0;
        data = new T[10];
    }
    ~MyVector()
    {
        delete[] data;
    }
    //Averrage:O(1)
    void push_back(T e)
    {
        if (size == capacity)
            resize(2 * capacity);
        data[size++] = e;
    }
    //Averrage:O(1)
    T pop_back(int n)
    {
        assert(size > 0);
        T ret = data[size - 1];
        size--;
        //复杂度的震荡
        //|
        //V
        /*if (size == capacity / 2)
            resize(capacity / 2);*/
            //没有复杂度的震荡
            //|
            //V
        if (size == capacity / n)
            resize(capacity / 2);
        return ret;
    }
};