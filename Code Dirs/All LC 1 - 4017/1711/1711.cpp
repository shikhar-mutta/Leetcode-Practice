// Link: https://leetcode.com/problems/count-good-meals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;
        for (int x : deliciousness) {
            for (long long sum = 1; sum <= 1LL << 21; sum <<= 1) {
                long long need = sum - x;
                if (freq.count((int)need)) count += freq[(int)need];
            }
            freq[x]++;
        }
        return (int)(count % MOD);
    }
};
