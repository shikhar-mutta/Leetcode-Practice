// Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum|words|*26) build worst-case (26 fixed), SC: O(sum|words|)
// Approach: trie where each node stores count of words passing through it; insert all words,
// then for each word walk down summing counts along the path.
class Solution {
public:
    struct Node { Node* child[26] = {}; int cnt = 0; };
    Node* root = new Node();

    void insert(const string& w) {
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
            cur->cnt++;
        }
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& w : words) insert(w);
        vector<int> ans;
        for (auto& w : words) {
            Node* cur = root;
            int score = 0;
            for (char c : w) {
                cur = cur->child[c - 'a'];
                score += cur->cnt;
            }
            ans.push_back(score);
        }
        return ans;
    }
};
