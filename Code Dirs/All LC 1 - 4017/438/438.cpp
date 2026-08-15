// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
// Approach: fixed-size sliding window of length |p|, maintain a count-diff
// array and a running "mismatch" counter, window is an anagram when 0
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (m > n) return res;

        int diff[26] = {0};
        for (char c : p) diff[c - 'a']++;
        int mismatches = 0;
        for (int i = 0; i < 26; i++) if (diff[i] != 0) mismatches++;

        auto adjust = [&](int idx, int delta) {
            int before = diff[idx];
            diff[idx] += delta;
            if (before == 0 && diff[idx] != 0) mismatches++;
            else if (before != 0 && diff[idx] == 0) mismatches--;
        };

        for (int i = 0; i < n; i++) {
            adjust(s[i] - 'a', -1);
            if (i >= m) adjust(s[i - m] - 'a', 1);
            if (i >= m - 1 && mismatches == 0) res.push_back(i - m + 1);
        }
        return res;
    }
};
