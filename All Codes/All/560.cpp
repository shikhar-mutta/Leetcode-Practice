// Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // Approach 1: Brute Force
        // int n = nums.size();
        // int count = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for (int j = i; j < n; j++)
        //     {
        //         sum += nums[j];
        //         if (sum == k)
        //             count++;
        //     }
        // }
        // return count;

        // Approach 2: Prefix Sum + Hash Map
        unordered_map<int, int> prefixCount{{0, 1}};
        int cnt = 0, prefixSum = 0;
        for (int x : nums)
        {
            prefixSum += x;
            auto it = prefixCount.find(prefixSum - k);
            if (it != prefixCount.end())
                cnt += it->second;
            prefixCount[prefixSum]++;
        }
        return cnt;
    }
};