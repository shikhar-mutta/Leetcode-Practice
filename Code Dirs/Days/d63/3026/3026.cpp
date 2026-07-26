// Link: https://leetcode.com/problems/maximum-good-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: For each j, a valid subarray ending at j needs some earlier
// nums[i] equal to nums[j]-k or nums[j]+k. Track, per value, the minimum
// prefix sum ending just before an index holding that value; then
// prefix[j] - minPrefixBefore[nums[j]±k] gives the best subarray sum ending
// at j for that pairing.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        long long prefix = 0;
        unordered_map<int, long long> mp;

        for (int j = 0; j < n; j++) {
            prefix += nums[j];

            auto it1 = mp.find(nums[j] - k);
            if (it1 != mp.end())
                ans = max(ans, prefix - it1->second);

            auto it2 = mp.find(nums[j] + k);
            if (it2 != mp.end())
                ans = max(ans, prefix - it2->second);

            long long prefixBeforeJ = prefix - nums[j];
            if (mp.find(nums[j]) == mp.end())
                mp[nums[j]] = prefixBeforeJ;
            else
                mp[nums[j]] = min(mp[nums[j]], prefixBeforeJ);
        }

        return ans == LLONG_MIN? 0: ans;
    }
};
