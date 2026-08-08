// Link: https://leetcode.com/problems/short-encoding-of-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum(len^2)) SC: O(sum(len))
// Approach: put all words in a set; remove any word that is a proper suffix of another word in the set. Remaining words each contribute len+1 to the encoding length.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (auto& w : words) {
            for (size_t i = 1; i < w.size(); i++) s.erase(w.substr(i));
        }
        int total = 0;
        for (auto& w : s) total += w.size() + 1;
        return total;
    }
};
