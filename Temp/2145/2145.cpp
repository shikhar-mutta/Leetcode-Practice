// Link: https://leetcode.com/problems/count-the-hidden-sequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0, minP = 0, maxP = 0;
        for (int d : differences) {
            prefix += d;
            minP = min(minP, prefix);
            maxP = max(maxP, prefix);
        }
        long long range = (long long)(upper - lower) - (maxP - minP) + 1;
        return (int)max(0LL, range);
    }
};
