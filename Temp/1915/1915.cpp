// Link: https://leetcode.com/problems/number-of-wonderful-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> freq(1024, 0);
        freq[0] = 1;
        int mask = 0;
        long long total = 0;
        for (char c : word) {
            mask ^= (1 << (c - 'a'));
            total += freq[mask];
            for (int b = 0; b < 10; b++) {
                total += freq[mask ^ (1 << b)];
            }
            freq[mask]++;
        }
        return total;
    }
};
