// Link: https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isDecomposable(string s) {
        int n = s.size();
        int i = 0;
        int countTwo = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            if (len % 3 == 1) return false;
            if (len % 3 == 2) countTwo++;
            i = j;
        }
        return countTwo <= 1;
    }
};
