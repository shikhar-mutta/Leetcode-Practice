// Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int best = -1;
        for (int x : nums)
            if (x > 0 && seen.count(-x)) best = max(best, x);
        return best;
    }
};
