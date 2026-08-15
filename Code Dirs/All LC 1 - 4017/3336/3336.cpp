// Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int subsequencePairCount(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<long long> cntDiv(maxVal + 1, 0);
        for (int x : nums) {
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    cntDiv[d]++;
                    int other = x / d;
                    if (other != d) cntDiv[other]++;
                }
            }
        }

        // Mobius function
        vector<int> mu(maxVal + 1, 1);
        vector<bool> isComposite(maxVal + 1, false);
        vector<int> primes;
        for (int i = 2; i <= maxVal; i++) {
            if (!isComposite[i]) { primes.push_back(i); mu[i] = -1; }
            for (int p : primes) {
                if ((long long)i * p > maxVal) break;
                isComposite[i*p] = true;
                if (i % p == 0) { mu[i*p] = 0; break; }
                else mu[i*p] = -mu[i];
            }
        }
        mu[1] = 1; // ensure (i starts at 1 in loop above but we set mu[1]=1 initially already; double-check overwritten)

        vector<long long> pow2(n + 1), pow3(n + 1);
        pow2[0] = 1; pow3[0] = 1;
        for (int i = 1; i <= n; i++) { pow2[i] = pow2[i-1] * 2 % MOD; pow3[i] = pow3[i-1] * 3 % MOD; }

        auto wantBothNonempty = [&](int a, int b) -> long long {
            long long ca = (a <= maxVal) ? cntDiv[a] : 0;
            long long cb = (b <= maxVal) ? cntDiv[b] : 0;
            long long g = __gcd(a, b);
            long long lcmv = (long long)a / g * b;
            long long cboth = (lcmv <= maxVal) ? cntDiv[lcmv] : 0;
            long long caOnly = ca - cboth;
            long long cbOnly = cb - cboth;
            long long total = pow3[cboth] * pow2[caOnly] % MOD * pow2[cbOnly] % MOD;
            long long res = (total - pow2[cb] - pow2[ca] + 1 + 2 * MOD) % MOD;
            return res;
        };

        long long ans = 0;
        for (int v = 1; v <= maxVal; v++) {
            int lim = maxVal / v;
            long long sub = 0;
            for (int e1 = 1; e1 <= lim; e1++) {
                if (mu[e1] == 0) continue;
                for (int e2 = 1; e2 <= lim; e2++) {
                    if (mu[e2] == 0) continue;
                    long long val = wantBothNonempty(v * e1, v * e2);
                    long long term = (long long)mu[e1] * mu[e2] % MOD * val % MOD;
                    sub = (sub + term) % MOD;
                }
            }
            ans = (ans + sub) % MOD;
        }

        ans = (ans % MOD + MOD) % MOD;
        return (int)ans;
    }
};
