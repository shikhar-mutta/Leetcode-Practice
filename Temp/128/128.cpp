// Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: hash set of all values; only start counting a run from a value with no predecessor (x-1 absent)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            if (s.count(x - 1)) continue;
            int len = 1;
            while (s.count(x + len)) len++;
            best = max(best, len);
        }
        return best;
    }
};
