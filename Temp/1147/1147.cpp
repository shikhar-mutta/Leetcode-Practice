// Link: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        if (n == 0) return 0;
        for (int len = 1; len <= n / 2; len++) {
            if (text.substr(0, len) == text.substr(n - len, len)) {
                return 2 + longestDecomposition(text.substr(len, n - 2*len));
            }
        }
        return 1;
    }
};
