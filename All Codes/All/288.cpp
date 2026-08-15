// Link: https://leetcode.com/problems/unique-word-abbreviation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len) per isUnique/abbr call, O(n*len) constructor  SC: O(n)
// Approach: map abbreviation -> set of distinct words with that abbreviation;
// isUnique is true iff no other distinct word shares the abbreviation
class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> abbrToWords;

    string abbr(const string& w) {
        if (w.size() <= 2) return w;
        return w.front() + to_string(w.size() - 2) + w.back();
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto& w : dictionary) {
            abbrToWords[abbr(w)].insert(w);
        }
    }

    bool isUnique(string word) {
        string a = abbr(word);
        auto it = abbrToWords.find(a);
        if (it == abbrToWords.end()) return true;
        return it->second.size() == 1 && it->second.count(word) == 1;
    }
};
