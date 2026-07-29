// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        string half;
        char mid = 0;
        for (int c = 0; c < 26; c++) {
            half += string(cnt[c] / 2, 'a' + c);
            if (cnt[c] % 2) mid = 'a' + c;
        }

        string result = half;
        if (mid) result += mid;
        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());
        result += revHalf;
        return result;
    }
};
