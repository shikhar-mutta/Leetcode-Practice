// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1);
        int start = 0, best = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (last[s[i]] >= start)
                start = last[s[i]] + 1;
            last[s[i]] = i;
            best = max(best, i - start + 1);
        }
        return best;
    }
};
