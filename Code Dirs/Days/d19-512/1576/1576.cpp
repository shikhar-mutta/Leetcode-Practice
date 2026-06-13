// Link: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string modifyString(string s)
    {
        string result = s;
        int n = result.size();
        for (int i = 0; i < n; ++i)
        {
            if (result[i] == '?')
            {
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if ((i > 0 && result[i - 1] == c) || (i < n - 1 && result[i + 1] == c))
                        continue;
                    result[i] = c;
                    break;
                }
            }
        }
        return result;
    }
};
