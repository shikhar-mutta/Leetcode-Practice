// Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (__int128)result * base % mod;
            base = (__int128)base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const long long MOD = 1000000007;
        int n = nums.size();

        if (multiplier == 1) {
            vector<int> res(n);
            for (int i = 0; i < n; i++) res[i] = nums[i] % MOD;
            return res;
        }

        const long long SAFE_MAX = 4000000000000000000LL;
        vector<long long> curVal(nums.begin(), nums.end());
        vector<long long> exponent(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        for (int i = 0; i < n; i++) pq.push({curVal[i], i});

        vector<char> windowSeen(n, 0);
        vector<int> windowOrder;
        windowOrder.reserve(n);

        long long opsDone = 0;
        bool cleanRoundFound = false;
        while (opsDone < k) {
            auto [v, idx] = pq.top(); pq.pop();
            if (v != curVal[idx]) continue; // stale entry

            exponent[idx]++;
            if (curVal[idx] > SAFE_MAX / multiplier) curVal[idx] = SAFE_MAX;
            else curVal[idx] *= multiplier;
            pq.push({curVal[idx], idx});
            opsDone++;

            if (windowSeen[idx]) {
                for (int x : windowOrder) windowSeen[x] = 0;
                windowOrder.clear();
            }
            windowSeen[idx] = 1;
            windowOrder.push_back(idx);
            if ((int)windowOrder.size() == n) {
                cleanRoundFound = true;
                break;
            }
        }

        if (cleanRoundFound && opsDone < k) {
            long long remaining = k - opsDone;
            long long fullRounds = remaining / n;
            long long rem = remaining % n;

            for (int i = 0; i < n; i++) exponent[i] += fullRounds;
            for (int i = 0; i < rem; i++) exponent[windowOrder[i]] += 1;
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            long long val = (long long)nums[i] % MOD;
            long long m = modpow(multiplier, exponent[i], MOD);
            res[i] = (int)((__int128)val * m % MOD);
        }
        return res;
    }
};
