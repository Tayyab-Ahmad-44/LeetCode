#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    const int mod = (int)pow(10, 9) + 7; // Modulo value for calculations

    // Function to calculate the number of ways to obtain a target sum using 'n' dice rolls with 'k' faces on each die
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // Create a 2D vector for memoization
        return recursion(dp, n, k, target);                         // Call the recursive function with memoization
    }

private:
    // Recursive function to calculate the number of ways to obtain the target sum
    int recursion(vector<vector<int>> &dp, int n, int k, int target)
    {
        // Base cases: if the target sum is reached with 'n' dice rolls or if 'n' becomes 0 or target reaches 0, return accordingly
        if (target == 0 && n == 0)
            return 1;
        if (n == 0 || target <= 0)
            return 0;

        // If the result is already computed, return the stored value from the memoization table
        if (dp[n][target] != -1)
            return dp[n][target] % mod;

        int ways = 0; // Variable to count the number of ways to obtain the target sum
        for (int i = 1; i <= k; i++)
        {
            // Calculate the number of ways by considering each possible face value of the die
            ways = (ways + recursion(dp, n - 1, k, target - i)) % mod;
        }
        dp[n][target] = ways % mod; // Store the computed result in the memoization table
        return dp[n][target];
    }
};

int main()
{

    return 0;
}

/*

1155. Number of Dice Rolls With Target Sum

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.


Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


*/

//!

/*

Approaches
(Also explained in the code)

Memoization: The solution uses a 2D array dp for memoization to store and reuse previously computed results. dp[n][target] stores the number of ways to obtain the target sum with 'n' dice rolls.

Recursion:

Base Cases:

If 'n' becomes 0 and the target becomes 0 (target == 0 && n == 0), there is exactly one way to achieve this - return 1.
If 'n' becomes 0 or the target reaches 0 (n == 0 || target <= 0), no further dice rolls are possible, so return 0.
Calculation:

If the result for the current state is already calculated (dp[n][target] != -1), return the stored result.
Otherwise, for each possible face value of the die (from 1 to 'k'), calculate the number of ways to achieve the target sum by recursively calling the function for 'n-1' dice rolls and subtracting the current face value from the target sum.
Accumulate these ways in the ways variable.
Memoize Result:

Store the computed result in the dp array to avoid recalculating the same state.
Return: Return the final count of ways modulo 10^9 + 7 to handle large values and provide the result.

Complexity
Time complexity:
O(n∗target∗k)O(n * target * k)O(n∗target∗k)
(where 'n' is the number of dice, 'k' is the number of faces, and 'target' is the target sum.)

Space complexity:
** O(n∗target)O(n * target)O(n∗target)**
(the space used by the memoization table (dp).)

*/