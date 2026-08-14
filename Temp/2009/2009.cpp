// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        int best = 0;
        for (int i = 0; i < m; i++) {
            int j = upper_bound(nums.begin(), nums.end(), nums[i] + n - 1) - nums.begin();
            best = max(best, j - i);
        }
        return n - best;
    }
};
