#pragma once
#include<bits/stdc++.h>
using namespace std;
const int M = 1000 + 5;
double c[M][M], w[M][M], p[M], q[M];
int s[M][M];
int n, i, j, k;
class Construct_Optimal_BST
{
public:
	static void Optimal_BST()
	{
		for (i = 1; i <= n + 1; i++)
		{
			c[i][i - 1] = 0.0;
			w[i][i - 1] = q[i - 1];
		}
		for (int t = 1; t <= n; t++)
		{
			for (i = 1; i <= n - t + 1; i++)
			{
				j = i + t - 1;
				w[i][j] = w[i][j - 1] + p[j] + q[j];
				c[i][j] = c[i][i - 1] + c[i + 1][j];
				s[i][j] = i;
				for (k = i + 1; k <= j; k++)
				{
					double temp = c[i][k - 1] + c[k + 1][j];
					if (temp < c[i][j] and fabs(temp - c[i][j])>1E-6)
					{
						c[i][j] = temp;
						s[i][j] = k;
					}
				}
				c[i][j] += w[i][j];
			}
		}
	}
	static void Construct_Optimal_BST_Function(int i, int j, bool flag)
	{
		if (flag == 0)
		{
			cout << "S" << s[i][j] << " �Ǹ�" << endl;
			flag = 1;
		}
		int k = s[i][j];
		if (k - 1 < i)
		{
			cout << "e" << k - 1 << " is the left child of " << "S" << k << endl;
		}
		else
		{
			cout << "S" << s[i][k - 1] << " is the left child of " << "S" << k << endl;
			Construct_Optimal_BST_Function(i, k - 1, 1);
		}
		if (k >= j)
		{
			cout << "e" << k << " is the right child of " << "S" << k << endl;
		}
		else
		{
			cout << "S" << s[k + 1][j] << " is the right child of " << "S" << k << endl;
			Construct_Optimal_BST_Function(k + 1, j, 1);
		}
	}
};