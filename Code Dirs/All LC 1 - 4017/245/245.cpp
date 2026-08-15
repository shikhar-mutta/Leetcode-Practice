// Link: https://leetcode.com/problems/shortest-word-distance-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: single pass tracking last-seen index of each word; when word1==word2, only update the
// running best on the second+ occurrence (comparing against the previous occurrence of the same word)
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int idx1 = -1, idx2 = -1, best = INT_MAX;
        bool same = (word1 == word2);
        for (int i = 0; i < (int)wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                if (same) {
                    if (idx1 != -1) best = min(best, i - idx1);
                    idx1 = i;
                } else {
                    idx1 = i;
                }
            } else if (wordsDict[i] == word2) {
                idx2 = i;
            }
            if (!same && idx1 != -1 && idx2 != -1) best = min(best, abs(idx1 - idx2));
        }
        return best;
    }
};
