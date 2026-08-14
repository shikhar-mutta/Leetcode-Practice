// Link: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char p0 = pattern[0], p1 = pattern[1];
        long long base = 0, countP0 = 0, countP1 = 0;
        for (char c : text) {
            if (c == p1) base += countP0;
            if (c == p0) countP0++;
            if (c == p1) countP1++;
        }
        return base + max(countP0, countP1);
    }
};
