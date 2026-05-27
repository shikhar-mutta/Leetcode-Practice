// Link: https://leetcode.com/problems/contains-duplicate-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> rec;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            auto it = rec.find(nums[i]);
            if (it != rec.end() && i - (*it).second <= k)
                return true;
            rec[nums[i]] = i;
        }
        return false;
    }
};