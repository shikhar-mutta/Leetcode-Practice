// Link: https://leetcode.com/problems/longest-word-in-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: sort words; maintain a set of "buildable" words (words whose every prefix exists in the input). A word is buildable if its length-1 prefix is buildable (or it's a single char). Track best buildable word using (longer, then lexicographically smaller) as tie-break.
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> buildable;
        string best = "";
        for (auto& w : words) {
            if (w.size() == 1 || buildable.count(w.substr(0, w.size()-1))) {
                buildable.insert(w);
                if (w.size() > best.size()) best = w;
            }
        }
        return best;
    }
};
