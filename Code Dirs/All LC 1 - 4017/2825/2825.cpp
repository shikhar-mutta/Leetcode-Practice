// Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0, n = str2.size();
        for (int i = 0; i < (int)str1.size() && j < n; i++) {
            char c1 = str1[i], c2 = (str1[i] - 'a' + 1) % 26 + 'a';
            if (c1 == str2[j] || c2 == str2[j]) j++;
        }
        return j == n;
    }
};
