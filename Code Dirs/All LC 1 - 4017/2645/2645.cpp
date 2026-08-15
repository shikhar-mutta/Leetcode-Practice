// Link: https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int pos = 0, additions = 0;
        while (pos < n) {
            for (char c : {'a','b','c'}) {
                if (pos < n && word[pos] == c) pos++;
                else additions++;
            }
        }
        return additions;
    }
};
