// Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int ans = -1;
        int index[26] = {-1};
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if (index[c] == -1)
                index[c] = i;
            else
                ans = max(ans, i - index[c] - 1);
        }
        return ans;
    }
};
