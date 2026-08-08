// Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<pair<int,int>> strength(m);
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int x : mat[i]) count += x;
            strength[i] = {count, i};
        }
        sort(strength.begin(), strength.end());
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(strength[i].second);
        return res;
    }
};
