// Link: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
//  Approach:
//    1. We can use a recursive approach to split the string into descending consecutive values
//    2. We can iterate through the string and for each character, we can check if the substring from the current character to the end of the string can be split into descending consecutive values
//    3. We can keep track of the previous value and check if the current value is equal to the previous value - 1
//    4. If we reach the end of the string and all the values are in descending order, we can return true. Otherwise, we can return false.
class Solution
{
public:
    bool splitString(string s)
    {
        int n = s.size();
        long long val = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            val = val * 10 + (s[i] - '0');
            if (val > 1e17)
                break; // no point in absurdly long first chunks
            if (dfs(s, i + 1, val))
                return true;
        }
        return false;
    }

private:
    bool dfs(const string &s, int start, long long prev)
    {
        if (start == s.size())
            return true;
        long long val = 0;
        for (int i = start; i < s.size(); ++i)
        {
            val = val * 10 + (s[i] - '0');
            if (val > prev - 1)
                break;
            if (val == prev - 1 && dfs(s, i + 1, val))
                return true;
        }
        return false;
    }
};
