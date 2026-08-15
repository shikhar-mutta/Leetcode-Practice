// Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ls = 1, cnt, x;
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto it : st)
        {
            // If the current number is the starting point of a sequence
            if (st.find(it - 1) == st.end())
            {
                x = it;
                cnt = 1;
                // Count the length of the sequence starting from 'x'
                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x++;
                }
                ls = max(ls, cnt);
            }
        }
        return ls;
    }
};