// Link: https://leetcode.com/problems/count-beautiful-substrings-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log k), SC: O(N)
// Approach: a beautiful substring has vowelCount==consonantCount==c with k | c^2. Factorize k to
// find the minimal M with M | c whenever k | c^2 (per prime p^e in k, need p^ceil(e/2) in M).
// Then track prefix (vowel-consonant diff, vowelCount mod M) pairs in a hashmap: a substring
// [l,r) is beautiful iff both endpoints share the same diff (balanced) and the same vowelCount
// mod M (so the vowel count difference is a multiple of M).
class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int M = 1;
        int kk = k;
        for (int p = 2; (long long)p * p <= kk; p++) {
            if (kk % p == 0) {
                int e = 0;
                while (kk % p == 0) { kk /= p; e++; }
                for (int i = 0; i < (e+1)/2; i++) M *= p;
            }
        }
        if (kk > 1) M *= kk;

        unordered_set<char> vowels = {'a','e','i','o','u'};
        unordered_map<long long, long long> counts;
        auto key = [&](int diff, int vmod) { return (long long)(diff + 100000) * 100000 + vmod; };

        int diff = 0, vowelCnt = 0;
        counts[key(0, 0)] = 1;
        long long ans = 0;
        for (char c : s) {
            bool isVowel = vowels.count(c);
            diff += isVowel ? 1 : -1;
            if (isVowel) vowelCnt++;
            int vmod = vowelCnt % M;
            long long kk2 = key(diff, vmod);
            ans += counts[kk2];
            counts[kk2]++;
        }
        return ans;
    }
};
