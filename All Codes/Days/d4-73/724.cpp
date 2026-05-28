// Link: https://leetcode.com/problems/find-pivot-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sl = 0, sr = 0, n = nums.size();
        for (auto it : nums)
            sr += it;
        for (int i = 0; i < n; i++)
        {
            sr -= nums[i];
            if (sl == sr)
                return i;
            sl += nums[i];
        }
        return -1;
    }
};
