// Link: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = 0;
                for (int k = 0; i + k < n && j + k < m; k++) {
                    if (s[i+k] != t[j+k]) diff++;
                    if (diff > 1) break;
                    if (diff == 1) total++;
                }
            }
        }
        return total;
    }
};
