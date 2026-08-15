// Link: https://leetcode.com/problems/3sum-with-multiplicity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long MOD = 1e9 + 7;
        unordered_map<int,long long> cnt;
        for (int x : arr) cnt[x]++;
        vector<int> keys;
        for (auto& [k, v] : cnt) keys.push_back(k);
        sort(keys.begin(), keys.end());

        long long res = 0;
        for (int i = 0; i < (int)keys.size(); i++) {
            int a = keys[i];
            for (int j = i; j < (int)keys.size(); j++) {
                int b = keys[j];
                int c = target - a - b;
                if (c < b) continue;
                if (!cnt.count(c)) continue;
                if (a == b && b == c) {
                    long long n = cnt[a];
                    res = (res + n * (n-1) * (n-2) / 6) % MOD;
                } else if (a == b) {
                    long long n = cnt[a];
                    res = (res + (n * (n-1) / 2) % MOD * cnt[c]) % MOD;
                } else if (b == c) {
                    long long n = cnt[b];
                    res = (res + cnt[a] * ((n * (n-1) / 2) % MOD)) % MOD;
                } else {
                    res = (res + cnt[a] * cnt[b] % MOD * cnt[c]) % MOD;
                }
            }
        }
        return (int)res;
    }
};
