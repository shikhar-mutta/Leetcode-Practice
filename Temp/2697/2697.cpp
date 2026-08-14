// Link: https://leetcode.com/problems/lexicographically-smallest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            char c = min(s[i], s[j]);
            s[i] = c;
            s[j] = c;
        }
        return s;
    }
};
