// Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int best = 0;
        int signs[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
        for (auto& s : signs) {
            int mn = INT_MAX, mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                int val = s[0]*arr1[i] + s[1]*arr2[i] + i;
                mn = min(mn, val);
                mx = max(mx, val);
            }
            best = max(best, mx - mn);
        }
        return best;
    }
};
