// Link: https://leetcode.com/problems/largest-palindromic-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {0};
        for (char c : num) cnt[c - '0']++;

        string half;
        for (int d = 9; d >= 0; d--) {
            int pairs = cnt[d] / 2;
            for (int i = 0; i < pairs; i++) {
                if (half.empty() && d == 0) continue; // avoid leading zero
                half += ('0' + d);
            }
        }

        char mid = -1;
        for (int d = 9; d >= 0; d--) {
            if (cnt[d] % 2 == 1) { mid = '0' + d; break; }
        }

        string result = half;
        if (mid != -1) result += mid;
        string rev = half;
        reverse(rev.begin(), rev.end());
        result += rev;

        if (result.empty()) return "0";
        return result;
    }
};
