// Link: https://leetcode.com/problems/count-binary-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: group consecutive equal chars into run lengths; for each adjacent pair of runs, valid substrings count is min(prevRun, curRun).
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0, cur = 1, total = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) cur++;
            else { total += min(prev, cur); prev = cur; cur = 1; }
        }
        total += min(prev, cur);
        return total;
    }
};
