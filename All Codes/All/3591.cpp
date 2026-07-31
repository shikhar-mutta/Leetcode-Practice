// Link: https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++) if (x % i == 0) return false;
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        for (auto& [v, c] : cnt) if (isPrime(c)) return true;
        return false;
    }
};
