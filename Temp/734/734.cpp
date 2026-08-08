// Link: https://leetcode.com/problems/sentence-similarity/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + p) SC: O(p)
// Approach: if lengths differ, not similar. Store pairs both directions in a hash set; each word pair must be equal or present in the similarity set.
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_set<string> pairs;
        for (auto& p : similarPairs) {
            pairs.insert(p[0] + "#" + p[1]);
            pairs.insert(p[1] + "#" + p[0]);
        }
        for (size_t i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) continue;
            if (!pairs.count(sentence1[i] + "#" + sentence2[i])) return false;
        }
        return true;
    }
};
