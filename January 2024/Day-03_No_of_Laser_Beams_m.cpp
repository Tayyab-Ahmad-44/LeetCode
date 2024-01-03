#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        //! These damn lines make your program runs faster AF !!
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int ans = 0;
        int prev = 0;

        for (size_t m = 0; m < bank.size(); m++)
        {
            int count = 0;
            for (size_t n = 0; n < bank[m].size(); n++)
                count += (bank[m][n] == '0') ? 0 : 1;
            if (count == 0)
            {
                if (m == bank.size() - 1)
                    ans += prev * count;
            }
            else
            {
                ans += prev * count;
                prev = count;
            }
        }

        return ans;
    }
};

int main()
{
    // vector<string> bank = {"011001", "000000", "010100", "001000"};
    vector<string> bank = {"000", "111", "000", "010"};
    Solution s;

    cout << s.numberOfBeams(bank);

    return 0;
}