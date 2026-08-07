// Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * len)  SC: O(1)
// Approach: for each dictionary word that is a subsequence of s, keep the
// best by (longest, then lexicographically smallest)
class Solution {
    bool isSubsequence(const string& w, const string& s) {
        int i = 0;
        for (char c : s) {
            if (i < (int)w.size() && w[i] == c) i++;
        }
        return i == (int)w.size();
    }

public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string best;
        for (auto& w : dictionary) {
            if (!isSubsequence(w, s)) continue;
            if (w.size() > best.size() || (w.size() == best.size() && w < best)) best = w;
        }
        return best;
    }
};
