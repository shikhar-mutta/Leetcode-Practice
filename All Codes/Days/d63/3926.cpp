// Link: https://leetcode.com/problems/count-valid-word-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(totalChunkLen + totalQueryLen) SC: O(same)
// Approach: concatenate chunks, then scan once building words: a
// hyphen only belongs to the current word if both its neighbors exist
// and are letters (a "joiner hyphen"); any other character (space, or a
// non-joiner hyphen) ends the current word. Count words in a hashmap
// and answer each query via lookup.
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for (auto& c : chunks) s += c;
        int n = s.size();

        unordered_map<string, int> wordCount;
        string cur;
        auto isLetter = [](char c) { return c >= 'a' && c <= 'z'; };
        for (int i = 0; i < n; i++) {
            char c = s[i];
            bool partOfWord = false;
            if (isLetter(c)) partOfWord = true;
            else if (c == '-' && i > 0 && i + 1 < n && isLetter(s[i-1]) && isLetter(s[i+1])) partOfWord = true;

            if (partOfWord) cur += c;
            else {
                if (!cur.empty()) { wordCount[cur]++; cur.clear(); }
            }
        }
        if (!cur.empty()) wordCount[cur]++;

        vector<int> ans;
        for (auto& q : queries) ans.push_back(wordCount.count(q) ? wordCount[q] : 0);
        return ans;
    }
};
