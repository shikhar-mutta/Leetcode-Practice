// Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s|)
// SC: O(1)
// Approach: greedily match t as a subsequence of s, where each s character
// may optionally be cyclically incremented once (z wraps to a) before
// comparing. Advance t's pointer whenever the current s char, as-is or
// incremented, matches t[j].
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.size() && j < t.size(); i++) {
            char current = s[i];
            char next = (current == 'z') ? 'a' : (current + 1);
            if (current == t[j] || next == t[j]) {
                j++;
            }
        }
        return j == t.size();
    }
};
