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
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (calculateHeight(root) == -1)
            return false;

        return true;
    }
    int calculateHeight(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int lH = calculateHeight(root->left);

        int rH = calculateHeight(root->right);

        if (lH == -1 || rH == -1 || abs(lH - rH) > 1)
            return -1;

        return max(lH, rH) + 1;
    }
};

int main()
{

    return 0;
}