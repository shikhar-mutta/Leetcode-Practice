// Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ops = 0;
        long long maxAllowed = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= maxAllowed) {
                maxAllowed = nums[i];
                continue;
            }
            long long k = (nums[i] + maxAllowed - 1) / maxAllowed;
            ops += k - 1;
            maxAllowed = nums[i] / k;
        }
        return ops;
    }
};
