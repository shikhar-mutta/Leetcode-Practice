// Link: https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const long long MOD = 1e9 + 7;
        int n = strength.size();

        vector<int> left(n), right(n);
        {
            vector<int> stk;
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && strength[stk.back()] >= strength[i]) stk.pop_back();
                left[i] = stk.empty() ? -1 : stk.back();
                stk.push_back(i);
            }
        }
        {
            vector<int> stk;
            for (int i = n - 1; i >= 0; i--) {
                while (!stk.empty() && strength[stk.back()] > strength[i]) stk.pop_back();
                right[i] = stk.empty() ? n : stk.back();
                stk.push_back(i);
            }
        }

        vector<long long> P(n + 1, 0), PP(n + 1, 0);
        for (int i = 0; i < n; i++) P[i+1] = (P[i] + strength[i]) % MOD;
        for (int i = 0; i <= n; i++) PP[i] = (i == 0 ? P[0] : (PP[i-1] + P[i]) % MOD);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lb = left[i], rb = right[i];
            long long leftCount = i - lb;
            long long rightCount = rb - i;
            long long sumRight = (PP[rb] - PP[i] % MOD + MOD) % MOD;
            long long sumLeft = (PP[i] - (lb >= 0 ? PP[lb] : 0) % MOD + MOD) % MOD;
            long long term = ((leftCount % MOD) * sumRight % MOD - (rightCount % MOD) * sumLeft % MOD + MOD) % MOD;
            term = term * (strength[i] % MOD) % MOD;
            ans = (ans + term) % MOD;
        }
        return (int)ans;
    }
};
