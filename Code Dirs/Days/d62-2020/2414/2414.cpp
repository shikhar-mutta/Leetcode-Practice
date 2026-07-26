// Link: https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: single pass tracking the length of the current run of
// consecutive alphabet letters (each char exactly one more than the
// previous); reset the run to 1 whenever that breaks, and track the
// longest run seen.
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1, run = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1] + 1) ++run;
            else run = 1;
            res = max(res, run);
        }
        return res;
    }
};
