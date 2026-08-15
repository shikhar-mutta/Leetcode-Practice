// Link: https://leetcode.com/problems/longest-square-streak-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = -1;
        for (int x : s) {
            long long v = x;
            int len = 1;
            while (s.count((int)(v * v)) && v * v <= 100000) {
                v *= v;
                len++;
            }
            if (len >= 2) best = max(best, len);
        }
        return best;
    }
};
