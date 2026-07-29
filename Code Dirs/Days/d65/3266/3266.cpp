// Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(bound * log N * 60) simulation + O(N log K) for final exponentiation, SC: O(N)
// Approach: raw values overflow almost immediately, so comparisons between two elements'
// "conceptual" values (nums[i] * multiplier^exponent[i]) are done exactly but cheaply: factor
// out the smaller exponent and multiply the other side up by the exponent difference, capped
// with an early exit once it provably exceeds the other (since multiplier>=2, this only ever
// takes a handful of steps). Simulate picks with a heap using this exact comparator. Adding a
// constant increment to whichever element is picked is a classic scheduling process that
// stabilizes into a period-N cycle after a bounded number of rounds; once two consecutive full
// periods of N picks match exactly, extrapolate the rest as full cycles (mod-pow) plus a partial
// cycle using the detected order.
class Solution {
public:
    int mult;
    vector<int>* numsPtr;
    vector<long long>* expPtr;

    // true if value(a) < value(b), exact (no overflow)
    bool valueLess(int a, int b) {
        auto& nums = *numsPtr;
        auto& exponent = *expPtr;
        long long ea = exponent[a], eb = exponent[b];
        const __int128 CAP = (__int128)4e18;
        if (ea <= eb) {
            long long diff = eb - ea;
            __int128 prod = nums[b];
            bool overflowed = false;
            for (long long i = 0; i < diff; i++) {
                prod *= mult;
                if (prod > CAP) { overflowed = true; break; }
            }
            if (overflowed) return true;
            return (__int128)nums[a] < prod;
        } else {
            long long diff = ea - eb;
            __int128 prod = nums[a];
            bool overflowed = false;
            for (long long i = 0; i < diff; i++) {
                prod *= mult;
                if (prod > CAP) { overflowed = true; break; }
            }
            if (overflowed) return false;
            return prod < (__int128)nums[b];
        }
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        const long long MOD = 1e9+7;
        vector<long long> exponent(n, 0);
        mult = multiplier;
        numsPtr = &nums;
        expPtr = &exponent;

        if (multiplier == 1) {
            vector<int> ans(n);
            for (int i = 0; i < n; i++) ans[i] = nums[i] % MOD;
            return ans;
        }

        auto cmp = [&](int a, int b) {
            if (a == b) return false;
            bool aLessB = valueLess(a, b);
            bool bLessA = valueLess(b, a);
            if (aLessB) return false; // a smaller -> a should be "greater" in max-heap sense to end on top
            if (bLessA) return true;
            return a > b; // tie: smaller index preferred (appears first)
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) pq.push(i);

        long long bound = min((long long)k, (long long)200 * n + 2000);
        vector<int> picks;
        picks.reserve(bound);
        long long done = 0;
        bool periodic = false;
        const int CONFIRM_WINDOWS = 3; // require this many consecutive matching periods

        while (done < bound) {
            int idx = pq.top(); pq.pop();
            exponent[idx]++;
            pq.push(idx);
            picks.push_back(idx);
            done++;

            if (done % n == 0 && done >= (long long)(CONFIRM_WINDOWS + 1) * n) {
                bool same = true;
                int sz = picks.size();
                for (int w = 1; w <= CONFIRM_WINDOWS && same; w++) {
                    for (int j = 0; j < n; j++) {
                        if (picks[sz - n + j] != picks[sz - (w + 1) * n + j]) { same = false; break; }
                    }
                }
                if (same) { periodic = true; break; }
            }
        }

        long long remaining = (long long)k - done;
        if (remaining > 0 && periodic) {
            vector<int> pattern(picks.end() - n, picks.end());
            long long fullCycles = remaining / n;
            long long rem = remaining % n;
            for (int i = 0; i < n; i++) exponent[i] += fullCycles;
            for (int j = 0; j < rem; j++) exponent[pattern[j]]++;
        } else if (remaining > 0) {
            while (remaining > 0) {
                int idx = pq.top(); pq.pop();
                exponent[idx]++;
                pq.push(idx);
                remaining--;
            }
        }

        auto power = [&](long long b, long long e) {
            long long r = 1; b %= MOD;
            while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
            return r;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long v = (long long)(nums[i] % MOD) * power(multiplier, exponent[i]) % MOD;
            ans[i] = (int)v;
        }
        return ans;
    }
};
