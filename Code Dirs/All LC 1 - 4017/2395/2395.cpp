// Link: https://leetcode.com/problems/find-subarrays-with-equal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            int s = nums[i] + nums[i+1];
            if (seen.count(s)) return true;
            seen.insert(s);
        }
        return false;
    }
};
