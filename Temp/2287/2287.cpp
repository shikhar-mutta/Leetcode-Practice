// Link: https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cntS[26] = {0}, cntT[26] = {0};
        for (char c : s) cntS[c - 'a']++;
        for (char c : target) cntT[c - 'a']++;
        int best = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cntT[i] > 0) best = min(best, cntS[i] / cntT[i]);
        }
        return best;
    }
};
