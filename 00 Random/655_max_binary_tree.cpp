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
    // TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    // {
    //     return construct(nums, 0, nums.size() - 1);
    // }

    // TreeNode *construct(vector<int> &nums, int start, int end)
    // {
    //     if (start > end)
    //     {
    //         return nullptr;
    //     }

    //     int maxIndex = start;
    //     for (int i = start + 1; i <= end; ++i)
    //     {
    //         if (nums[i] > nums[maxIndex])
    //         {
    //             maxIndex = i;
    //         }
    //     }

    //     TreeNode *root = new TreeNode(nums[maxIndex]);

    //     root->left = construct(nums, start, maxIndex - 1);

    //     root->right = construct(nums, maxIndex + 1, end);

    //     return root;
    // }

    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        vector<TreeNode *> stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode *cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};

int main()
{

    return 0;
}