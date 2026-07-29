// Link: https://leetcode.com/problems/minimum-removals-to-balance-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, best = 0;
        for (int right = 0; right < n; right++) {
            while ((long long)nums[left] * k < nums[right]) left++;
            best = max(best, right - left + 1);
        }
        return n - best;
    }
};
