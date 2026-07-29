// Link: https://leetcode.com/problems/count-number-of-trapezoids-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> cntByY;
        for (auto& p : points) cntByY[p[1]]++;

        vector<long long> pairs;
        for (auto& [y, c] : cntByY) pairs.push_back(c * (c - 1) / 2);

        long long ans = 0;
        long long prefix = 0; // running sum mod MOD
        for (long long a : pairs) {
            long long aMod = a % MOD;
            ans = (ans + (__int128)prefix * aMod % MOD) % MOD;
            prefix = (prefix + aMod) % MOD;
        }

        return (int)ans;
    }
};
