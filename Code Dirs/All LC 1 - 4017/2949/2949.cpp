// Link: https://leetcode.com/problems/count-beautiful-substrings-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int minSquareDivisible(int k) {
        int m0 = 1;
        for (int p = 2; (long long)p * p <= k; p++) {
            if (k % p == 0) {
                int e = 0;
                while (k % p == 0) { k /= p; e++; }
                int need = (e + 1) / 2;
                for (int i = 0; i < need; i++) m0 *= p;
            }
        }
        if (k > 1) m0 *= k; // remaining prime factor with exponent 1, need power 1
        return m0;
    }

    long long beautifulSubstrings(string s, int k) {
        int n = s.size();
        int m0 = minSquareDivisible(k);
        vector<map<int,long long>> cnt(2 * n + 2);
        auto& base = cnt[n]; // balance offset by n to allow negative index
        base[0 % m0] = 1;
        int bal = 0, vow = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) vow++, bal++;
            else bal--;
            int idx = bal + n;
            int key = vow % m0;
            auto it = cnt[idx].find(key);
            if (it != cnt[idx].end()) ans += it->second;
            cnt[idx][key]++;
        }
        return ans;
    }
};
