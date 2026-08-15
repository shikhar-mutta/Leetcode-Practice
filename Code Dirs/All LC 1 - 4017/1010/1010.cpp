// Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        long long res = 0;
        for (int t : time) {
            int r = t % 60;
            int need = (60 - r) % 60;
            res += cnt[need];
            cnt[r]++;
        }
        return (int)res;
    }
};
