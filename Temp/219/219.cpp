// Link: https://leetcode.com/problems/contains-duplicate-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(min(n,k))
// Approach: hash map of value -> last seen index; check if the gap to a repeat is within k
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastIdx;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = lastIdx.find(nums[i]);
            if (it != lastIdx.end() && i - it->second <= k) return true;
            lastIdx[nums[i]] = i;
        }
        return false;
    }
};
