//给定一个二叉树，返回所有从根节点到叶子节点的路径。
 // @lc code=start
#include<bits/stdc++.h>
using namespace std;
//* Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {

		vector<string> res;
		if (root == NULL)
			return res;

		stack<pair<TreeNode*, string>> stack;
		stack.push(make_pair(root, to_string(root->val)));
		while (!stack.empty()) {
			TreeNode* cur = stack.top().first;
			string s = stack.top().second;
			stack.pop();

			if (!cur->left && !cur->right)
				res.push_back(s);

			if (cur->left)
				stack.push(make_pair(cur->left, s + "->" + to_string(cur->left->val)));
			if (cur->right)
				stack.push(make_pair(cur->right, s + "->" + to_string(cur->right->val)));
		}
		return res;
	}
};

// @lc code=end
