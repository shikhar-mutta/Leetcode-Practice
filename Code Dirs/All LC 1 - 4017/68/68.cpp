// Link: https://leetcode.com/problems/text-justification/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * maxWidth)  SC: O(n * maxWidth)
// Approach: greedy line-fill (pack as many words as fit), then distribute spaces evenly with extra
// spaces going to the leftmost gaps; last line and single-word lines are left-justified with trailing padding
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();
        while (i < n) {
            int j = i, lineLen = 0;
            while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }
            int numWords = j - i;
            int totalSpace = maxWidth - lineLen;
            string line;
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int gaps = numWords - 1;
                int base = totalSpace / gaps, extra = totalSpace % gaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = base + (k - i < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};
