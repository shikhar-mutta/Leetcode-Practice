#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store element -> index
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            // If complement found, return indices
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            // Store current element and index
            mp[nums[i]] = i;
        }
        return {-1, -1}; // No pair found
    }
};