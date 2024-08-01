#include <iostream>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        for (int i = 0; i < s.length(); 1)
        {
            if (s[i] == '#')
            {
                if (i == 0)
                {
                    s.erase(0, 1);
                    continue;
                }
                s.erase(i - 1, 2);
                i = i - 1;
                continue;
            }
            i++;
        }

        for (int i = 0; i < t.length(); 1)
        {
            if (t[i] == '#')
            {
                if (i == 0)
                {
                    t.erase(0, 1);
                    continue;
                }
                t.erase(i - 1, 2);
                i = i - 1;
                continue;
            }
            i++;
        }

        if (s.compare(t) == 0)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}
