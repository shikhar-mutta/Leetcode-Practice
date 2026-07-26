// Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n = s.size()
// SC: O(1)
// Approach: greedily two-pointer match t as a subsequence of s, advancing
// the t-pointer only on a match. Whatever suffix of t remains unmatched
// once s is exhausted must be appended, so the answer is t's remaining
// length.
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int p = t.size();
        int i = 0;
        int j = 0;
        while (i < n && j < p) {

            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return p - j;
    }
};
