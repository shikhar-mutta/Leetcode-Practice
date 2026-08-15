// Link: https://leetcode.com/problems/reverse-only-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalpha(s[i])) { i++; continue; }
            if (!isalpha(s[j])) { j--; continue; }
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};
