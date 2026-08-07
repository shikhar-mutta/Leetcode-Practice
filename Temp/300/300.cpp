// Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: maintain tails[] of smallest tail for each subsequence length,
// binary search to replace/extend
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }
};
