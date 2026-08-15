// Link: https://leetcode.com/problems/valid-palindrome-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: two pointers; on first mismatch, try skipping either the left or right character and check if the remainder is a palindrome.
class Solution {
    bool isPalin(const string& s, int l, int r) {
        while (l < r) { if (s[l++] != s[r--]) return false; }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r]) return isPalin(s, l+1, r) || isPalin(s, l, r-1);
            l++; r--;
        }
        return true;
    }
};
