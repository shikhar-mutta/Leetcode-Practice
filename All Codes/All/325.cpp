// Link: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: prefix sum + hashmap of first index each prefix sum was seen;
// for prefix[i]=s, look for prefix[j]=s-k with j earliest
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> firstIdx;
        firstIdx[0] = -1;
        int sum = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            auto it = firstIdx.find(sum - k);
            if (it != firstIdx.end()) best = max(best, i - it->second);
            if (!firstIdx.count(sum)) firstIdx[sum] = i;
        }
        return best;
    }
};
