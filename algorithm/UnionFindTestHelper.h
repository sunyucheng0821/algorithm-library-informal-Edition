#pragma once
#include<iostream>
#include<cassert>
#include<ctime>
#include"Union-Path-Compression.h"
#include"Optimize-by-Rank.h"
#include"Optimize-by-Size.h"
#include"Union-Path-Compression.h"
#include"Unionfind-Quick-find.h"
#include"Unionfind-Quick-Union.h"
#include"Optional-06-Same-Case-Test-for-UF.h"
using namespace std;
namespace UnionFindTestHelper
{
	void testUF1(int n)
	{
		srand(time(NULL));
		UF1::UnionFind uf = UF1::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind1, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
	void testUF2(int n)
	{
		srand(time(NULL));
		UF2::UnionFind uf = UF2::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind2, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
	void testUF3(int n)
	{
		srand(time(NULL));
		UF3::UnionFind uf = UF3::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind3, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
	void testUF4(int n)
	{
		srand(time(NULL));
		UF4::UnionFind uf = UF4::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind4, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
	void testUF5(int n)
	{
		srand(time(NULL));
		UF5::UnionFind uf = UF5::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind5, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
	void testUF6(int n)
	{
		srand(time(NULL));
		UF6::UnionFind uf = UF6::UnionFind(n);
		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		cout << "UnionFind6, " << 2 * n << "ops," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
	}
}