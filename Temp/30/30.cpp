// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*wordLen)  SC: O(words)
// Approach: sliding window of word-sized units, one pass per starting offset (0..wordLen-1);
// maintain a count map of words in the window, shrinking from the left when a word's count exceeds need
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int numWords = words.size();
        int windowLen = wordLen * numWords;
        int n = s.size();
        if (n < windowLen) return res;
        unordered_map<string,int> need;
        for (auto& w : words) need[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string,int> window;
            int count = 0, left = offset;
            for (int i = offset; i + wordLen <= n; i += wordLen) {
                string word = s.substr(i, wordLen);
                if (need.count(word)) {
                    window[word]++;
                    count++;
                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == numWords) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = i + wordLen;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
