// Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words) {
            string r = w;
            reverse(r.begin(), r.end());
            if (r == w) return w;
        }
        return "";
    }
};
