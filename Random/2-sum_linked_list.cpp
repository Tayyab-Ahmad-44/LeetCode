#include <iostream>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *addedNumbers;
        int num1 = l1->val, num2 = l2->val;
        bool first = true;

        while (l1 != nullptr)
        {
            if (first)
            {
                num1 = l1->val;
                first = false;
            }
            else
                num1 = (num1 * 10) + l1->val;
            l1 = l1->next;
        }

        first = true;

        while (l1 != nullptr)
        {
            if (first)
            {
                num2 = l2->val;
                first = false;
            }
            else
                num2 = (num2 * 10) + l2->val;
            l2 = l2->next;
        }

        return addedNumbers;
    }
};
