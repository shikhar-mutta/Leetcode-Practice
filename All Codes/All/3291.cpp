// Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum(|words|) * |target|), SC: same
// Approach: For each word, build the KMP failure function (LPS array) of
// word + '#' + target; the LPS value at the position corresponding to a
// given target suffix tells the longest prefix of that word matching that
// suffix of target starting at the current point. Greedily, from the
// currently unmatched suffix length, pick the word giving the longest
// prefix-match jump, repeating until the whole target is covered (or fail
// if no word can extend further).
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int ans = 0;
        int unmatched = target.length();
        vector<vector<int>> lps_list;

        for (const string& word : words) {
            lps_list.push_back(LSP(word + '#' + target));
        }

        while (unmatched > 0) {
            int max_suf = 0;
            for (int i = 0; i < words.size(); ++i) {
                max_suf =
                    max(max_suf, lps_list[i][words[i].length() + unmatched]);
            }
            if (max_suf == 0) {
                return -1;
            }
            ++ans;
            unmatched -= max_suf;
        }

        return ans;
    }

private:
    vector<int> LSP(const string& pattern) {
        vector<int> lps(pattern.length());
        for (int i = 1, j = 0; i < pattern.length(); ++i) {
            while (j > 0 && pattern[j] != pattern[i]) {
                j = lps[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                lps[i] = ++j;
            }
        }
        return lps;
    }
};
