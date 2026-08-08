// Link: https://leetcode.com/problems/remove-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev) return s.empty() ? 0 : 1;
        return 2;
    }
};
