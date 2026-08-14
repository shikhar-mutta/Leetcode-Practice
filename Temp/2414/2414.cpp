// Link: https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int best = 1, cur = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == s[i-1] + 1) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best;
    }
};
