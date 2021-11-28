#pragma once
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Command
{
    string s;
    TreeNode* node;
    Command(string s, TreeNode* node) :s(s), node(node) {}
};