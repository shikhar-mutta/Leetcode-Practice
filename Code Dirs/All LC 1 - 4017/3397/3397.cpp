// Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = LLONG_MIN;
        int count = 0;
        for (int num : nums) {
            long long lo = (long long)num - k, hi = (long long)num + k;
            long long cand = max(lo, prev + 1);
            if (cand <= hi) {
                count++;
                prev = cand;
            }
        }
        return count;
    }
};
