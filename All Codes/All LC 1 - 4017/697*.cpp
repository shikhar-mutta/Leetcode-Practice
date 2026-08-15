// Link: https://leetcode.com/problems/degree-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        // count, first, last
        unordered_map<int, array<int, 3>> mp; // {count, first, last}
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (!mp.count(nums[i]))
                mp[nums[i]] = {1, i, i};
            else
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
        }
        int degree = 0, mn = 0;
        // find the degree and the minimum length of subarray with the same degree
        for (auto &[num, info] : mp)
        {
            // info[0] is the count, info[1] is the first index, info[2] is the last index
            int len = info[2] - info[1] + 1;
            // info[0] is the count, if it's greater than the current degree, update the degree and the minimum length
            if (info[0] > degree || (info[0] == degree && len < mn))
            {
                degree = info[0];
                mn = len;
            }
        }
        return mn;
    }
};
