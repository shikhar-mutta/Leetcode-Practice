// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach:
    //   1. We will keep track of the prefix sum of the array and store it in a map.
    //   2. We will iterate through the array and for each element, we will check if the prefix sum - target exists in the map.
    //   3. If it exists, we will increment the answer and update the threshold to the current index.
    //   4. We will also update the prefix sum in the map.
    //   5. We will return the answer.
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int presum = 0;
        int threshold = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            presum += nums[i];
            int req = presum - target;
            if (mp.find(req) != mp.end() && mp[req] >= threshold)
            {
                ans += 1;
                threshold = i;
                presum = 0;
            }
            mp[presum] = i;
        }
        return ans;
    }
};