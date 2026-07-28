// Link: https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: monotonic increasing stack building the lexicographically
// smallest subsequence of length k. Pop a larger top char only if enough
// characters remain afterward to fill the stack to length k, and popping
// wouldn't drop the letter count below the required repetition.
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        int totalLetter = count(s.begin(), s.end(), letter);
        string stk;
        int stkLetter = 0;
        int remainingLetter = totalLetter;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            while (!stk.empty() && stk.back() > c &&
                   (int)(stk.size() - 1 + n - i) >= k &&
                   (stk.back() != letter || stkLetter - 1 + remainingLetter >= repetition)) {
                if (stk.back() == letter) stkLetter--;
                stk.pop_back();
            }
            if ((int)stk.size() < k) {
                if (c == letter) {
                    stk += c;
                    stkLetter++;
                } else if ((int)(k - stk.size()) > (repetition - stkLetter)) {
                    stk += c;
                }
            }
            if (c == letter) remainingLetter--;
        }
        return stk;
    }
};
