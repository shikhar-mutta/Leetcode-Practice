// Link: https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int best = 0;
        int i = 0;
        while (i < n) {
            if (nums[i] % 2 != 0 || nums[i] > threshold) { i++; continue; }
            int j = i + 1;
            while (j < n && nums[j] <= threshold && nums[j] % 2 != nums[j-1] % 2) j++;
            best = max(best, j - i);
            i = j;
        }
        return best;
    }
};
