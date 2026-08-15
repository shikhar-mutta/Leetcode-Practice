// Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);
        for (auto& row : grid) for (int x : row) freq[x]++;
        int rep = -1, miss = -1;
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2) rep = i;
            if (freq[i] == 0) miss = i;
        }
        return {rep, miss};
    }
};
