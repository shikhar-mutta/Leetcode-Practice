// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        string left = "";
        char mid = 0;
        for (int c = 0; c < 26; c++) {
            left += string(freq[c] / 2, 'a' + c);
            if (freq[c] % 2 == 1) mid = 'a' + c;
        }
        string right(left.rbegin(), left.rend());
        return left + (mid ? string(1, mid) : "") + right;
    }
};
