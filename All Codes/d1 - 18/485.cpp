// Link: https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                cnt++;
            else
                cnt = 0;
            mx = max(mx, cnt);
        }
        return mx;
    }
};