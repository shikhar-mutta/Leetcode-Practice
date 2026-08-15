// Link: https://leetcode.com/problems/binary-search/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = (int)nums.size() - 1, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
