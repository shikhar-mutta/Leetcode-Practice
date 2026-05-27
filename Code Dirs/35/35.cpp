// Link: https://leetcode.com/problems/search-insert-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int cnt = 0, n = nums.size();
        while (cnt < n)
        {
            if (nums[cnt] >= target)
                break;
            cnt++;
        }
        return cnt;
    }
};