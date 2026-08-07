// Link: https://leetcode.com/problems/permutation-in-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
// Approach: fixed-size sliding window of length |s1|, maintain a mismatch
// count via a diff array
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        int diff[26] = {0};
        for (char c : s1) diff[c - 'a']++;
        int mismatches = 0;
        for (int i = 0; i < 26; i++) if (diff[i] != 0) mismatches++;

        auto adjust = [&](int idx, int delta) {
            int before = diff[idx];
            diff[idx] += delta;
            if (before == 0 && diff[idx] != 0) mismatches++;
            else if (before != 0 && diff[idx] == 0) mismatches--;
        };

        for (int i = 0; i < m; i++) {
            adjust(s2[i] - 'a', -1);
            if (i >= n) adjust(s2[i - n] - 'a', 1);
            if (i >= n - 1 && mismatches == 0) return true;
        }
        return false;
    }
};
