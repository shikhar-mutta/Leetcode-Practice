// Link: https://leetcode.com/problems/maximum-erasure-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0;
        long long sum = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            sum += nums[right];
            best = max(best, sum);
        }
        return (int)best;
    }
};
