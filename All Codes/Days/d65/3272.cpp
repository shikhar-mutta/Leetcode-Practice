// Link: https://leetcode.com/problems/find-the-count-of-good-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^(n/2) * n), SC: O(distinct multisets)
// Approach: n <= 10, so enumerate every n-digit palindrome by choosing its first half (no
// leading zero), check divisibility by k, and record its digit-multiset (sorted digit string) in
// a set to dedupe. For each distinct good multiset, count how many distinct n-digit arrangements
// (no leading zero) it produces via a multinomial-coefficient formula, and sum.
class Solution {
public:
    long long fact[11];

    long long countArrangements(int cnt[10], int n) {
        long long total = fact[n];
        for (int d = 0; d < 10; d++) total /= fact[cnt[d]];

        if (cnt[0] == 0) return total;
        // subtract arrangements with leading zero
        cnt[0]--;
        long long withZeroLead = fact[n-1];
        for (int d = 0; d < 10; d++) withZeroLead /= fact[cnt[d]];
        cnt[0]++;
        return total - withZeroLead;
    }

    long long countGoodIntegers(int n, int k) {
        fact[0] = 1;
        for (int i = 1; i <= 10; i++) fact[i] = fact[i-1] * i;

        int half = (n + 1) / 2;
        long long lo = 1, hi = 9;
        for (int i = 1; i < half; i++) { lo *= 10; hi = hi * 10 + 9; }

        set<string> goodMultisets;
        for (long long h = lo; h <= hi; h++) {
            string hs = to_string(h);
            string pal = hs;
            if (n % 2 == 0) {
                string rev = hs;
                reverse(rev.begin(), rev.end());
                pal += rev;
            } else {
                string rev = hs.substr(0, half-1);
                reverse(rev.begin(), rev.end());
                pal += rev;
            }
            long long val = stoll(pal);
            if (val % k != 0) continue;
            string sorted_s = pal;
            sort(sorted_s.begin(), sorted_s.end());
            goodMultisets.insert(sorted_s);
        }

        long long ans = 0;
        for (auto& ms : goodMultisets) {
            int cnt[10] = {};
            for (char c : ms) cnt[c-'0']++;
            ans += countArrangements(cnt, n);
        }
        return ans;
    }
};
