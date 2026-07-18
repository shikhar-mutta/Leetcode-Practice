// Link: https://leetcode.com/problems/find-special-substring-of-length-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        // Scan each maximal run of identical chars; a special substring of
        // length exactly k exists iff some run has length == k.
        int n = s.size();
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) ++j;   // extend run [i, j)
            if (j - i == k) return true;
            i = j;
        }
        return false;
    }
};
