// Link: https://leetcode.com/problems/shortest-word-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: single pass tracking the last-seen index of each target word, updating the running
// minimum distance whenever both have been seen
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int idx1 = -1, idx2 = -1, best = INT_MAX;
        for (int i = 0; i < (int)wordsDict.size(); i++) {
            if (wordsDict[i] == word1) idx1 = i;
            else if (wordsDict[i] == word2) idx2 = i;
            if (idx1 != -1 && idx2 != -1) best = min(best, abs(idx1 - idx2));
        }
        return best;
    }
};
