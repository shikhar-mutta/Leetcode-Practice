// Link: https://leetcode.com/problems/longest-common-suffix-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        int bestIdx = -1;
        int bestLen = INT_MAX;
    };

    void updateNode(TrieNode* node, int idx, int len) {
        if (len < node->bestLen) {
            node->bestLen = len;
            node->bestIdx = idx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < (int)wordsContainer.size(); i++) {
            string& w = wordsContainer[i];
            int len = w.size();
            updateNode(root, i, len);
            TrieNode* cur = root;
            for (int j = (int)w.size() - 1; j >= 0; j--) {
                int c = w[j] - 'a';
                if (!cur->children[c]) cur->children[c] = new TrieNode();
                cur = cur->children[c];
                updateNode(cur, i, len);
            }
        }

        vector<int> res;
        for (auto& q : wordsQuery) {
            TrieNode* cur = root;
            int bestIdx = root->bestIdx;
            for (int j = (int)q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';
                if (!cur->children[c]) break;
                cur = cur->children[c];
                bestIdx = cur->bestIdx;
            }
            res.push_back(bestIdx);
        }
        return res;
    }
};
