// Link: https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> vals(nums.begin(), nums.end());
        long long best = vals[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (vals[i] <= vals[i+1]) {
                vals[i] += vals[i+1];
            }
            best = max(best, vals[i]);
        }
        return best;
    }
};
