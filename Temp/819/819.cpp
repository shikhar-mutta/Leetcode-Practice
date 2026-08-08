// Link: https://leetcode.com/problems/most-common-word/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: tokenize paragraph into lowercase words (treating non-letters as separators), count frequencies, skip banned words, track the max.
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string,int> cnt;
        string word;
        string best;
        int bestCnt = 0;
        auto flush = [&]() {
            if (word.empty()) return;
            for (char& c : word) c = tolower(c);
            if (!bannedSet.count(word)) {
                int c = ++cnt[word];
                if (c > bestCnt) { bestCnt = c; best = word; }
            }
            word.clear();
        };
        for (char c : paragraph) {
            if (isalpha(c)) word += c;
            else flush();
        }
        flush();
        return best;
    }
};
