// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for (auto& s : arr) {
            int mask = 0;
            bool valid = true;
            for (char c : s) {
                int bit = 1 << (c - 'a');
                if (mask & bit) { valid = false; break; }
                mask |= bit;
            }
            if (valid) masks.push_back(mask);
        }
        int best = 0;
        vector<int> dp = {0};
        for (int m : masks) {
            int sz = dp.size();
            for (int i = 0; i < sz; i++) {
                if (!(dp[i] & m)) {
                    int combined = dp[i] | m;
                    dp.push_back(combined);
                    best = max(best, __builtin_popcount(combined));
                }
            }
        }
        return best;
    }
};
