// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: if some character occurs more than once, exactly one occurrence
// of some duplicated character must be removed; try removing each position
// whose character has count>=2 and keep the lexicographically smallest
// resulting string. If no character repeats, the string is returned as-is.
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        bool hasDup = false;
        for (int c : cnt) if (c >= 2) hasDup = true;
        if (!hasDup) return s;

        string best;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (cnt[s[i] - 'a'] < 2) continue;
            string candidate = s.substr(0, i) + s.substr(i + 1);
            if (first || candidate < best) { best = candidate; first = false; }
        }
        return best;
    }
};
