// Link: https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: split into words, count vowels in the first word as the
// target, then reverse each subsequent word whose vowel count matches
// the target before rejoining.
class Solution {
    bool isVowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
    int vowelCount(const string& w) {
        int c = 0;
        for (char ch : w) if (isVowel(ch)) c++;
        return c;
    }
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) words.push_back(w);

        int target = vowelCount(words[0]);
        for (int i = 1; i < (int)words.size(); i++) {
            if (vowelCount(words[i]) == target) reverse(words[i].begin(), words[i].end());
        }

        string res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i) res += ' ';
            res += words[i];
        }
        return res;
    }
};
