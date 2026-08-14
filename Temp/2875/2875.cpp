// Link: https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;

        long long numFull = target / total;
        long long rem = target % total;
        if (rem == 0) {
            if (numFull == 0) return 0;
            numFull--;
            rem = total;
        }

        vector<int> doubled(nums);
        doubled.insert(doubled.end(), nums.begin(), nums.end());
        int minLen = INT_MAX;
        long long sum = 0;
        int l = 0;
        for (int r = 0; r < (int)doubled.size(); r++) {
            sum += doubled[r];
            while (sum > rem) { sum -= doubled[l]; l++; }
            if (sum == rem) minLen = min(minLen, r - l + 1);
        }
        if (minLen == INT_MAX) return -1;
        return (int)(numFull * n + minLen);
    }
};
