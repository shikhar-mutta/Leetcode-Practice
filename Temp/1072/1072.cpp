// Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> cnt;
        for (auto& row : matrix) {
            string pattern;
            for (int x : row) pattern += (x == row[0] ? '0' : '1');
            cnt[pattern]++;
        }
        int best = 0;
        for (auto& [p, c] : cnt) best = max(best, c);
        return best;
    }
};
