
#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<cassert>
const int DefaultSize = 128;
using std::cout;
using std::endl;
 
enum NodeInfo { Empty, Active, Delete };//记录节点的状态
 
template<typename K>
class HashTable
{
public:
	HashTable(int d,int sz= DefaultSize);
	~HashTable();
	void PrintValue();
 
	bool Search(const K& k);//查看键码k是否存在
	bool Insert(const K& k);//插入键码k
	bool Remove(const K& k);//删除键码k
 
private:
 
	int FindPos1(const K& k)const;//寻找键k在哈希表的存储数组中对应的位置，使用线性探查法
	int FindPos2(const K& k)const;//寻找键k在哈希表的存储数组中对应的位置，使用二次探查法
 
	int curSize, maxSize;//curSize存储当前哈希表存储节点的数量，maxSize为哈希表最多存储的节点的数量
	NodeInfo* info;//存储每个节点的状态数组，作为辅助数组
	int divitor;//散列表的除数
	K* value;//哈希表的存储节点的数组
};
 
 
#endif // !HASHTABLE_H
 
template<typename K>
HashTable<K>::HashTable(int d, int sz)
{
	divitor = d;
	maxSize = sz;
	curSize = 0;
	value = new K[maxSize];
	info = new NodeInfo[maxSize];
	assert(value && info);
	for (int i = 0; i < maxSize; i++)//所有节点状态都设为空
		info[i] = Empty;
}
 
template<typename K>
HashTable<K>::~HashTable()
{
	if (value) delete[] value;
	if (info) delete[] info;
}
 
template<typename K>
void HashTable<K>::PrintValue()
{
	for (int i = 0; i < maxSize; i++)
	{
		if (info[i] == Active) cout << value[i] << " ";
		else cout << 0 << " ";
	}
	cout << endl;
}
 
//查看键码k是否存在
template<typename K>
bool HashTable<K>::Search(const K& k)
{
	if (FindPos1(k) >= 0)
		return true;
	return false;
}
 
template<typename K>
bool HashTable<K>::Insert(const K& k)
{
	if (FindPos1(k) >= 0) return false;
	int i = k % divitor;
	int j = i;//j作为移动的指针
	do
	{
		if (info[j] == Empty) {//当节点状态为空时，进行插入，否则j将一直移动下去
			value[j] = k;
			info[j] = Active;
			curSize++;
			return true;
		}
		else
			j = (j + 1) % maxSize;
	} while (j != i);
	return false;
}
 
template<typename K>
bool HashTable<K>::Remove(const K& k)
{
	int x = FindPos1(k);
	if (x < 0) return false;
	else {
		info[x] = Delete;
		curSize--;
		return true;
	}
}
 
//寻找键k在哈希表的存储数组中对应的位置，使用线性探测法
template<typename K>
int HashTable<K>::FindPos1(const K& k) const
{
	int i = k % divitor;
	if (info[i] == Empty) return -1;//如果info状态为空，那么该键码不存在哈希表中
	int j = i;//j作为移动的指针
	do
	{
		if (info[j] == Active && value[j] == k) return j;//如果节点转态为Active，且value数组在j处值为k
		j = (j + 1) % maxSize;//位移
	} while (j != i);
	return -1;
}
 
//寻找键k在哈希表的存储数组中对应的位置，使用二次探查法
template<typename K>
int HashTable<K>::FindPos2(const K& k) const
{
	int i = k % divitor;
	int flag = 0;//控制加减号，由于每次进进行移动时+1，-1，+4，-4.....
	int save, j = 0;//j代表每次递增进位
	while (info[i] == Delete || info[i] == Active && value[i] != k)//每次循环flag变化一次
	{
		if (flag == 0)
		{
			save = i;//保存此时的i值,下次循环时时使用
			j++;
			i = (i + 2 * j - 1) % maxSize;//2*j-1，是+1变成+4需要增加增量，这里不使用平方，平方耗时
			i = (i < 0) ? (i + maxSize) : i;//当i为0时，第一次循环时i会变为负值，将其变为正值
			flag = 1;
		}
		else
		{
			i = (save - 2 * j + 1) % maxSize;
			i = (i < 0) ? (i + maxSize) : i;
			flag = 0;
		}
	}
	if (info[i] == Empty) return -1;
	else if(value[i] == k) return i;
}