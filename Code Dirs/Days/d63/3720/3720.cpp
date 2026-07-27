// Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26) SC: O(n)
// Approach: greedily try to match target exactly using the available
// multiset of s's characters as far as possible; that longest matchable
// prefix is where any "increase" (strictly greater char) must happen for
// the smallest result — keeping the tie prefix as long as possible.
// Starting from that break point, walk backward: at each candidate
// position, look for the smallest available char strictly greater than
// target there; if found, place it and fill the rest ascending (smallest
// completion). If not found, undo the match at the previous position
// (restore its char to the pool) and try one position earlier.
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int matchLen = 0;
        while (matchLen < n && count[target[matchLen] - 'a'] > 0) {
            count[target[matchLen] - 'a']--;
            matchLen++;
        }

        int pos;
        if (matchLen == n) {
            pos = n - 1;
            count[target[pos] - 'a']++; // undo last match to test increasing here
        } else {
            pos = matchLen;
        }

        while (pos >= 0) {
            int chosen = -1;
            for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                if (count[c] > 0) { chosen = c; break; }
            }
            if (chosen != -1) {
                string result = target.substr(0, pos);
                result += (char)('a' + chosen);
                count[chosen]--;
                for (int c = 0; c < 26; c++) {
                    result.append(count[c], (char)('a' + c));
                }
                return result;
            }
            if (pos == 0) break;
            count[target[pos-1] - 'a']++; // undo match at pos-1
            pos--;
        }
        return "";
    }
};
