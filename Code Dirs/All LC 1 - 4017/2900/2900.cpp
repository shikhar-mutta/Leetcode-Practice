// Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int lastGroup = -1;
        for (int i = 0; i < (int)words.size(); i++) {
            if (res.empty() || groups[i] != lastGroup) {
                res.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        return res;
    }
};
