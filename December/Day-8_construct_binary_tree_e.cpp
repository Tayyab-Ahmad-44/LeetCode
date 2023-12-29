#include <iostream>

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
    string tree2str(TreeNode *root)
    {
        string str = "";
        check(root, str);
        return str;
    }

    void check(TreeNode *root, string &str)
    {
        if (root == NULL)
            return;

        str += to_string(root->val);
        if (root->left || root->right)
        {
            str += '(';
            check(root->left, str);
            str += ')';
        }

        if (root->right)
        {
            str += '(';
            check(root->right, str);
            str += ')';
        }
    }
};

int main()
{
    return 0;
}

/*
606. Construct String from Binary Tree

Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:

Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

Example 2:

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.


By one-to-one, the author is trying to say that you need a preceding "()" only to indicate that the next "(n)" is a right child,
where n is just the value of the right child. If we don't include the preceding parentheses, we can't tell whether it's the left or right child,
whereas, if a node doesn't have a right child but has a left child, it's implicitly understood that a single parenthesis containing the
left child's value refers to the left child of a given node.

*/