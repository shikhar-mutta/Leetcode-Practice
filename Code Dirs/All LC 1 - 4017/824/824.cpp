// Link: https://leetcode.com/problems/goat-latin/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) worst case (string append) SC: O(n)
// Approach: tokenize by space; for each word, move leading consonant to the end (or keep if vowel-starting), append "ma", then append "a" repeated (index+1) times.
class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        stringstream ss(sentence);
        string word, res;
        int idx = 0;
        while (ss >> word) {
            if (!res.empty()) res += " ";
            idx++;
            if (!vowels.count(word[0])) {
                word = word.substr(1) + word[0];
            }
            word += "ma";
            word += string(idx, 'a');
            res += word;
        }
        return res;
    }
};
