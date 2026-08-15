// Link: https://leetcode.com/problems/range-product-queries-of-powers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) {
            if (e & 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int b = 0; b < 32; b++)
            if (n & (1 << b)) powers.push_back(b);

        vector<int> ans;
        for (auto &q : queries) {
            long long expSum = 0;
            for (int i = q[0]; i <= q[1]; i++) expSum += powers[i];
            ans.push_back((int)power(2, expSum));
        }
        return ans;
    }
};
