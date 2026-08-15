// Link: https://leetcode.com/problems/find-missing-observations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long long total = (long long)mean * (m + n);
        long long sumKnown = accumulate(rolls.begin(), rolls.end(), 0LL);
        long long need = total - sumKnown;
        if (need < n || need > 6LL * n) return {};
        int base = need / n;
        int rem = need % n;
        vector<int> res(n, base);
        for (int i = 0; i < rem; i++) res[i]++;
        return res;
    }
};
