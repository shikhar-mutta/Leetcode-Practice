// Link: https://leetcode.com/problems/double-modular-exponentiation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(long long b, long long e, long long m) {
        long long r = 1; b %= m;
        while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; }
        return r;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < (int)variables.size(); i++) {
            long long a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            long long val = power(power(a, b, 10), c, m);
            if (val == target) res.push_back(i);
        }
        return res;
    }
};
