#pragma once
#include<bits/stdc++.h>
#include"TraversalHelper(≤È’“ ˜).h"
using namespace std;
// @lc code=start
class  InorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty())
        {
            Command command = stack.top();
            stack.pop();
            if (command.s == "print")
                res.push_back(command.node->val);
            else
            {
                assert(command.s == "go");
                if (command.node->right)
                    stack.push(Command("go", command.node->right));
                stack.push(Command("print", command.node));
                if (command.node->left)
                    stack.push(Command("go", command.node->left));
            }
        }
        return res;
    }
};
// @lc code=end

