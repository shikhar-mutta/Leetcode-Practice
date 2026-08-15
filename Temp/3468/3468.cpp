// Link: https://leetcode.com/problems/find-the-number-of-copy-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        long long lo = LLONG_MIN, hi = LLONG_MAX;
        for (int i = 0; i < (int)original.size(); i++) {
            long long l = bounds[i][0] - original[i];
            long long h = bounds[i][1] - original[i];
            lo = max(lo, l);
            hi = min(hi, h);
        }
        return (int)max(0LL, hi - lo + 1);
    }
};
