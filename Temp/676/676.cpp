// Link: https://leetcode.com/problems/implement-magic-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*L) buildDict, O(L^2) search SC: O(n*L)
// Approach: store dictionary words in a hash set grouped by length. search() tries every single-character substitution of the query and checks if the modified word (different from original) exists in the set.
class MagicDictionary {
    unordered_set<string> words;
public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (auto& w : dictionary) words.insert(w);
    }

    bool search(string searchWord) {
        for (int i = 0; i < (int)searchWord.size(); i++) {
            char orig = searchWord[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                searchWord[i] = c;
                if (words.count(searchWord)) { searchWord[i] = orig; return true; }
            }
            searchWord[i] = orig;
        }
        return false;
    }
};
