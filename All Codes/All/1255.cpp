// Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * wordLen)  n = words.size() (<=14)  SC: O(1) extra
//  Approach: backtracking over the subset of words (include/exclude
//  each), maintaining the remaining letter counts. For an included word,
//  verify enough letters remain (deduct them), compute its score, and
//  recurse; skip it if letters run out.
class Solution
{
    int letterCount[26];
    int scoreOf(const string &w, vector<int> &score)
    {
        int s = 0;
        for (char c : w)
            s += score[c - 'a'];
        return s;
    }
    int backtrack(vector<string> &words, int idx, vector<int> &score)
    {
        if (idx == (int)words.size())
            return 0;
        int skip = backtrack(words, idx + 1, score);

        string &w = words[idx];
        int cnt[26] = {};
        bool ok = true;
        for (char c : w)
        {
            cnt[c - 'a']++;
            if (cnt[c - 'a'] > letterCount[c - 'a'])
                ok = false;
        }
        int take = 0;
        if (ok)
        {
            for (int i = 0; i < 26; i++)
                letterCount[i] -= cnt[i];
            take = scoreOf(w, score) + backtrack(words, idx + 1, score);
            for (int i = 0; i < 26; i++)
                letterCount[i] += cnt[i];
        }
        return max(skip, take);
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters,
                      vector<int> &score)
    {
        memset(letterCount, 0, sizeof(letterCount));
        for (char c : letters)
            letterCount[c - 'a']++;
        return backtrack(words, 0, score);
    }
};
