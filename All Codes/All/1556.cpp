// Link: https://leetcode.com/problems/thousand-separator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string thousandSeparator(int n)
    {
        string numStr = to_string(n);
        string result;

        int count = 0;
        for (int i = numStr.size() - 1; i >= 0; --i)
        {
            result += numStr[i], count++;
            if (count == 3 && i != 0)
                result += '.', count = 0;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
