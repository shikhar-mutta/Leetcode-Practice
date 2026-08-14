// Link: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long value = 0;
        int length = 0, power = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                length++;
                power++;
            } else {
                if (power < 31 && value + (1LL << power) <= k) {
                    value += (1LL << power);
                    length++;
                    power++;
                }
            }
        }
        return length;
    }
};
