// Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) (n = words.size(); map has at most 26*26 distinct 2-letter keys)
// SC: O(1) (bounded map of at most 676 entries)
// Approach: count occurrences of each 2-letter word. A word like "ab" pairs
// with its reverse "ba" to form a 4-letter palindrome chunk ("ab"+"ba"), so
// for each word processed only once (via w < rev to avoid double-counting
// the pair from both sides), add 4 * min(count[w], count[rev]). Self-
// palindromic words ("aa") pair with themselves - each pair of two "aa"s
// contributes 4, and if an odd one is left over, one such word can sit
// alone in the very center, adding 2.
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto& w : words)
            ++cnt[w];

        int length = 0;
        bool center = false;
        for (auto& [w, c] : cnt) {
            string rev = {w[1], w[0]};
            if (w == rev) {
                length += (c / 2) * 4; // pairs of self-palindromic words
                if (c % 2)
                    center = true; // one can go in the middle
            } else if (w < rev) {
                int pairs = min(c, cnt.count(rev) ? cnt[rev] : 0);
                length += pairs * 4; // match with reversed counterpart
            }
        }
        if (center)
            length += 2;
        return length;
    }
};
