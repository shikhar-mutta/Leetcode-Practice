// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int best = 1;
        for (int x : arr) {
            int len = 1;
            if (dp.count(x - difference)) len = dp[x - difference] + 1;
            dp[x] = len;
            best = max(best, len);
        }
        return best;
    }
};
