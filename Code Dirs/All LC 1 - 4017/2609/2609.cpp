// Link: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int best = 0;
        int i = 0;
        while (i < n) {
            int zeroStart = i;
            while (i < n && s[i] == '0') i++;
            int zeros = i - zeroStart;
            int ones = 0;
            while (i < n && s[i] == '1') { ones++; i++; }
            best = max(best, 2 * min(zeros, ones));
        }
        return best;
    }
};
