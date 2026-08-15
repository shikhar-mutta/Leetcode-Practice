// Link: https://leetcode.com/problems/find-substring-with-given-hash-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long p = power, mod = modulo;
        auto val = [&](char c) { return (long long)(c - 'a' + 1); };

        long long H = 0, pw = 1;
        for (int j = 0; j < k; j++) {
            H = (H + val(s[n - k + j]) * pw) % mod;
            if (j < k - 1) pw = (pw * p) % mod;
        }
        long long pk = (pw * p) % mod; // p^k mod mod

        int answer = -1;
        if (H == hashValue) answer = n - k;

        for (int i = n - k - 1; i >= 0; i--) {
            long long term = (val(s[i]) + p * H % mod - pk * val(s[i + k]) % mod) % mod;
            term = ((term % mod) + mod) % mod;
            H = term;
            if (H == hashValue) answer = i;
        }
        return s.substr(answer, k);
    }
};
