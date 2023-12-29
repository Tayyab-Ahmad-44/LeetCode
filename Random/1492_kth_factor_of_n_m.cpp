#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        std::vector<int> factors;
        int sqrt_n = sqrt(n);

        for (int i = 1; i <= sqrt_n; ++i)
            if (n % i == 0)
            {
                factors.push_back(i);
                if (i != n / i)
                    factors.push_back(n / i);
            }

        std::sort(factors.begin(), factors.end());

        if (k <= factors.size())
            return factors[k - 1];

        else
            return -1;
    }
};

int main()
{
    Solution s;
    std::cout << s.kthFactor(12, 3) << std::endl; // Output: 3
    std::cout << s.kthFactor(7, 2) << std::endl;  // Output: 7
    std::cout << s.kthFactor(4, 4) << std::endl;  // Output: -1

    return 0;
}
/*
1492. The kth Factor of n
Hint
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.



Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.


Constraints:

1 <= k <= n <= 1000


Follow up:

Could you solve this problem in less than O(n) complexity?
*/