// Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size(), ls = 1, cnt;
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                cnt = 1;
                while (st.find(it + 1) != st.end())
                {
                    cnt++;
                    it++;
                }
                ls = max(ls, cnt);
            }
        }
        return ls;
    }
};