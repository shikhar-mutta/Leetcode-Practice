// Link: https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        map<int, int> count;
        for (auto& arr : arrays) {
            for (int x : arr) count[x]++;
        }
        vector<int> res;
        int n = arrays.size();
        for (auto& [val, c] : count) {
            if (c == n) res.push_back(val);
        }
        return res;
    }
};
