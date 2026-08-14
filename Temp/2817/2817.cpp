// Link: https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        multiset<int> seen;
        int ans = INT_MAX;
        for (int i = x; i < n; i++) {
            seen.insert(nums[i - x]);
            auto it = seen.lower_bound(nums[i]);
            if (it != seen.end()) ans = min(ans, abs(*it - nums[i]));
            if (it != seen.begin()) { --it; ans = min(ans, abs(*it - nums[i])); }
        }
        return ans;
    }
};
