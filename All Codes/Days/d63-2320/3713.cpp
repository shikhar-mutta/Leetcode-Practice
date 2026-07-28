// Link: https://leetcode.com/problems/longest-balanced-substring-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * 26) SC: O(1)
// Approach: n is small, so try every starting index and extend the
// substring right, maintaining per-letter counts. At each extension,
// check whether every present letter has the same count (all distinct
// nonzero frequencies equal); track the longest such length.
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int target = -1;
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0) continue;
                    if (target == -1) target = freq[k];
                    else if (freq[k] != target) { ok = false; break; }
                }
                if (ok) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};
