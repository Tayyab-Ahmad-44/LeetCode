#include <iostream>

using namespace std;

//  Definition for a binary tree node.
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
    void rangeSum(TreeNode *root, int low, int high, int &sum)
    {
        if (root == NULL)
            return;

        if (root->val >= low && root->val <= high)
            sum += root->val;

        rangeSum(root->left, low, high, sum);
        rangeSum(root->right, low, high, sum);

        return;
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;

        rangeSum(root, low, high, sum);

        return sum;
    }
};

int main()
{

    return 0;
}

/*

938. Range Sum of BST
Easy

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].


Example 1:

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.


Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.


*/