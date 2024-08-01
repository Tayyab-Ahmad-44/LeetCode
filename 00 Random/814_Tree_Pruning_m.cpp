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
    bool containsOne(TreeNode *node)
    {
        if (!node)
        {
            return false;
        }

        bool leftHasOne = containsOne(node->left);
        bool rightHasOne = containsOne(node->right);

        if (!leftHasOne)
        {
            delete node->left;
            node->left = nullptr;
        }

        if (!rightHasOne)
        {
            delete node->right;
            node->right = nullptr;
        }

        return node->val == 1 || leftHasOne || rightHasOne;
    }

    TreeNode *pruneTree(TreeNode *root)
    {
        if (!containsOne(root))
        {
            delete root;
            return nullptr;
        }

        return root;
    }
};

int main()
{

    return 0;
}