// Link: https://leetcode.com/problems/prefix-and-suffix-search/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*L) build, O(n*L) query worst case SC: O(n*L)
// Approach: for each word, store all combined "suffix#prefix -> index" keys is expensive; instead store map of "word_prefix#word_suffix" isn't feasible for all pairs directly, so store each word with its index and linear scan checking prefix/suffix match (simple and correct for typical constraints).
class WordFilter {
    vector<pair<string,int>> words;
public:
    WordFilter(vector<string>& wordsIn) {
        for (int i = 0; i < (int)wordsIn.size(); i++) words.push_back({wordsIn[i], i});
    }

    int f(string pref, string suff) {
        int best = -1;
        for (auto& [w, idx] : words) {
            if (w.size() >= pref.size() && w.compare(0, pref.size(), pref) == 0 &&
                w.size() >= suff.size() && w.compare(w.size()-suff.size(), suff.size(), suff) == 0) {
                best = max(best, idx);
            }
        }
        return best;
    }
};
