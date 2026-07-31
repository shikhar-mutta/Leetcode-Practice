// Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of words and m is the length of the target string
// SC: O(n * m) where n is the number of words and m is the length of the target string
// Approach: We can use the KMP algorithm to find the longest prefix-suffix (LPS) array for each word concatenated with the target string. We can then use a greedy approach to find the minimum number of valid strings needed to form the target string.

class Solution
{
public:
    // 3291. Minimum Number of Valid Strings to Form Target I
    int minValidStrings(vector<string> &words, string target)
    {
        int ans = 0;
        int unmatchedPrefix = target.length();
        vector<vector<int>> lpsList;

        for (const string &word : words)
            lpsList.push_back(getLPS(word + '#' + target));

        while (unmatchedPrefix > 0)
        {
            // Greedily choose the word that has the longest suffix match with
            // the remaining unmatched prefix.
            int maxMatchSuffix = 0;
            for (int i = 0; i < words.size(); ++i)
                maxMatchSuffix =
                    max(maxMatchSuffix,
                        lpsList[i][words[i].length() + unmatchedPrefix]);
            if (maxMatchSuffix == 0)
                return -1;
            ++ans;
            unmatchedPrefix -= maxMatchSuffix;
        }

        return ans;
    }

private:
    // Returns the lps array, where lps[i] is the length of the longest prefix
    // of pattern[0..i] which is also a suffix of this substring.
    vector<int> getLPS(const string &pattern)
    {
        vector<int> lps(pattern.length());
        for (int i = 1, j = 0; i < pattern.length(); ++i)
        {
            while (j > 0 && pattern[j] != pattern[i])
                j = lps[j - 1];
            if (pattern[i] == pattern[j])
                lps[i] = ++j;
        }
        return lps;
    }
};
