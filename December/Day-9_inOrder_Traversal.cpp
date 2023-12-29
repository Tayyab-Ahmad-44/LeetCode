#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void traversal(TreeNode *node, vector<int> &res)
    {
        if (node == NULL)
            return;

        traversal(node->left, res);
        res.push_back(node->val);
        traversal(node->right, res);

        return;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;

        traversal(root, res);

        return res;
    }
};

/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/