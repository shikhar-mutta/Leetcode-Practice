// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1); // last seen index of each char
        int best = 0, left = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (last[(unsigned char)s[i]] >= left)
                left = last[(unsigned char)s[i]] + 1; // shrink window past the repeat
            last[(unsigned char)s[i]] = i;
            best = max(best, i - left + 1);
        }
        return best;
    }
};
