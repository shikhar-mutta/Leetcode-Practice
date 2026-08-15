// Link: https://leetcode.com/problems/sentence-similarity-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((p+n) α) SC: O(p)
// Approach: union-find over all words in similarPairs; words in the same component are transitively similar. Check length match, then for each position words are similar if equal or share the same root.
class Solution {
    unordered_map<string,string> parent;
    string find(const string& x) {
        if (!parent.count(x)) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(const string& a, const string& b) {
        parent[find(a)] = find(b);
    }
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        for (auto& p : similarPairs) unite(p[0], p[1]);
        for (size_t i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) continue;
            if (find(sentence1[i]) != find(sentence2[i])) return false;
        }
        return true;
    }
};
