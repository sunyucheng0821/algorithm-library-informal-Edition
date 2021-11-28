//二叉搜索树中的两个节点被错误地交换。

//请在不改变其结构的情况下，恢复这棵树。
#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
// * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		if (root == NULL)
			return;
		InOrderTraverse(root);
	}
	void InOrderTraverse(TreeNode* root) {
		stack<TreeNode*> S;
		TreeNode* p = root;
		vector<int> num;
		TreeNode* tmp = NULL;
		TreeNode* big = NULL;
		TreeNode* small = NULL;
		bool flag = false;
		while (p || !S.empty()) {
			if (p) {
				S.push(p);
				p = p->left;
			}
			else {
				p = S.top();
				S.pop();
				if (tmp == NULL) {
					tmp = p;
					p = p->right;
					continue;
				}
				if (!flag) {
					if (tmp->val > p->val) {
						big = tmp;
						small = p;
						flag = true;
					}
				}
				else {
					if (tmp->val > p->val) {
						small = p;
						break;
					}
				}
				tmp = p;
				p = p->right;
			}
		}
		int a = big->val;
		big->val = small->val;
		small->val = a;
	}
};