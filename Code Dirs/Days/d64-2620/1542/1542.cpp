// Link: https://leetcode.com/problems/find-longest-awesome-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: We can use a bitmask to represent the count of each digit in the substring. We can iterate through the string and for each character, we can update the bitmask accordingly. We can also keep track of the first occurrence of each bitmask in a dp array. Whenever we encounter a bitmask that we have seen before, we can calculate the length of the substring and update the result accordingly. We can also check for all possible bitmasks that differ by one bit to account for the case where we can have one odd count of a digit in the substring. Finally, we can return the result as the length of the longest awesome substring.
class Solution
{
public:
    int longestAwesome(string s)
    {
        vector<int> dp(1024, s.size());
        int res = 0, mask = 0;
        dp[0] = -1;
        for (auto i = 0; i < s.size(); ++i)
        {
            mask ^= 1 << (s[i] - '0');
            res = max(res, i - dp[mask]);
            for (auto j = 0; j <= 9; ++j)
                res = max(res, i - dp[mask ^ (1 << j)]);
            dp[mask] = min(dp[mask], i);
        }
        return res;
    }
};