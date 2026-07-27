// Link: https://leetcode.com/problems/longest-balanced-subarray-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: n is small, so for each starting index extend right while
// tracking sets of distinct even/odd values seen; whenever the two set
// sizes match, record the length.
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> evens, odds;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) evens.insert(nums[j]);
                else odds.insert(nums[j]);
                if (evens.size() == odds.size()) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};
