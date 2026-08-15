// Link: https://leetcode.com/problems/valid-word-abbreviation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers over word and abbr; digits in abbr accumulate a
// skip count (no leading zero), letters must match exactly
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < (int)word.size() && j < (int)abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j < (int)abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;
            } else {
                if (word[i] != abbr[j]) return false;
                i++; j++;
            }
        }
        return i == (int)word.size() && j == (int)abbr.size();
    }
};
