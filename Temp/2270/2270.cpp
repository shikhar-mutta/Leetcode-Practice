// Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0;
        int count = 0;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            left += nums[i];
            long long right = total - left;
            if (left >= right) count++;
        }
        return count;
    }
};
