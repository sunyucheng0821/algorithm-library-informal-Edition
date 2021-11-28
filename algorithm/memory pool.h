#pragma once
#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
class MemmoryBlock
{
public:
	int nSize;
	int nFree;
	int nFirst;
	MemmoryBlock* pNext;
	char aData[1];

	//private:
public:
	MemmoryBlock(int unitCount, int unitSize)
	{
		nSize = unitCount * unitSize;
		nFree = unitCount;
		nFirst = 0;
		pNext = NULL;
		char* p = aData;
		for (int i = 0; i < unitCount - 1; ++i)
		{
			*((short*)p) = i + 1;
			p += unitSize;
		}
		*((short*)p) = -1;
	}
	void* operator new(size_t t, int size)
	{
		int headSize = sizeof(MemmoryBlock);
		return ::operator new(headSize + size);
	}
};
class MemoryPool
{
public:
	int ulnitCount;
	int nGrowSize;
	int nUnitSize;
	MemmoryBlock* pBlock;
	//private:
public:
	MemoryPool(int _ulnitCount, int _nGrowSize, int _nUnitSize)
	{
		ulnitCount = _ulnitCount;
		nGrowSize = _nGrowSize;
		nUnitSize = _nUnitSize;
		pBlock = NULL;
	}
	char* Alloc()
	{
		if (pBlock == NULL)
		{
			MemmoryBlock* p = (MemmoryBlock*)new(ulnitCount * nUnitSize)MemmoryBlock(ulnitCount, nUnitSize);
			assert(p != NULL);

			pBlock = p;
		}
		MemmoryBlock* pB = pBlock;
		while (pB != NULL && pB->nFree == 0)
		{
			pB = pB->pNext;
		}
		if (pB == NULL)
		{
			pB = (MemmoryBlock*)new(nGrowSize * nUnitSize)MemmoryBlock(nGrowSize, nUnitSize);
			assert(pB != NULL);

			pB->pNext = pBlock;
			pBlock = pB;

			pB = pBlock;
		}

		char* pFree = pB->aData + pB->nFirst * nUnitSize;
		pB->nFirst = *((short*)pFree);
		pB->nFree--;

		return pFree;
	}
	void Free(void* p)
	{
		MemmoryBlock* pB = pBlock;
		while (pB != NULL && p < pB->aData || p>pB->aData + pB->nSize)
		{
			pB = pB->pNext;
		}
		if (pB != NULL)
		{
			*((short*)p) = pB->nFirst;
			pB->nFirst = ((char*)p - pB->aData) / nUnitSize;
			pB->nFree++;
		}
		else
		{
			printf("错误，此内存不是用内存池分配的！");
		}
	}
	void Print()
	{
		printf("\n\n\n");
		MemmoryBlock* pB = pBlock;
		while (pB != NULL)
		{
			printf("\n首地址:%p 总大小：%d 空闲个数：%d 下一个空间：%d\n", pB->aData, pB->nSize, pB->nFree, pB->nFirst);
			for (int i = 0; i < pB->nSize / nUnitSize; ++i)
			{
				printf("%d ", *((int*)(pB->aData + i * nUnitSize)));
			}
			pB = pB->pNext;
			printf("\n----------------------------------------------------\n");
		}
	}
};