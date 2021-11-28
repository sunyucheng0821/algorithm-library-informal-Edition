#pragma once
//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
//
//请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
//示例:
//
//你可以将以下二叉树：
//
//   1
//  / \
//  2  3
// /   \
// 4    5
//
//序列化为 "[1,2,3,null,null,4,5]"



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


class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

		if (!root)
			return "[null]";

		string ret = "[";
		dfs(root, ret);
		ret.pop_back();
		return ret + "]";
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> vec = get_vector(data);

		if (vec.size() == 0 || (vec.size() == 1 && vec[0] == "null"))
			return NULL;

		//        for(const string& s: vec)
		//            cout << s << " ";
		//        cout << endl;

		int index = 0;
		return dfs(vec, index);
	}

private:
	TreeNode* dfs(const vector<string>& vec, int& index) {

		if (index == vec.size() || vec[index] == "null")
			return NULL;

		TreeNode* node = new TreeNode(atoi(vec[index].c_str()));
		index++;
		node->left = dfs(vec, index);

		index++;
		node->right = dfs(vec, index);

		return node;
	}

	void dfs(TreeNode* node, string& ret) {

		ret += to_string(node->val) + ",";

		if (node->left)
			dfs(node->left, ret);
		else
			ret += "null,";

		if (node->right)
			dfs(node->right, ret);
		else
			ret += "null,";
	}

	vector<string> get_vector(const string& data) {

		string s = data.substr(1, data.size() - 2) + ",";

		vector<string> res;
		int i = 0;
		while (i < s.size()) {
			int comma = s.find(',', i);
			res.push_back(s.substr(i, comma - i));
			i = comma + 1;
		}
		return res;
	}
};

// @lc code=end

