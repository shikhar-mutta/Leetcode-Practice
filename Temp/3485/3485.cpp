// Link: https://leetcode.com/problems/longest-common-prefix-of-k-strings-after-removal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct trie_node {
        int cnt = 0;
        int best = 0;
        trie_node* child[26];
        trie_node() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    trie_node* root;

public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> answer(n, 0);
        trie_node* root = new trie_node();
        for (int i = 0; i < n; i++)
            insertWord(root, words[i]);
        helper(root, k);

        auto getRootSiblingsBest = [&](char firstChar) -> int {
            int ret = 0;
            for (int c = 0; c < 26; c++) {
                if (c == (firstChar - 'a')) continue;
                if (root->child[c] && root->child[c]->best != -1) {
                    ret = max(ret, 1 + root->child[c]->best);
                }
            }
            return ret;
        };

        for (int i = 0; i < n; i++) {
            int candidate = getRootSiblingsBest(words[i][0]);
            trie_node* cur = root;
            int depth = 0;
            bool broken = false;
            for (int j = 0; j < (int)words[i].size(); j++) {
                int idx = words[i][j] - 'a';
                if (!cur->child[idx]) {
                    broken = true;
                    break;
                }
                cur = cur->child[idx];
                depth++;
                if (cur->cnt > k) {
                    candidate = max(candidate, depth);
                } else {
                    candidate = max(candidate, depth - 1);
                    broken = true;
                    break;
                }
                if (j + 1 < (int)words[i].size()) {
                    for (int c = 0; c < 26; c++) {
                        if (c == (words[i][j + 1] - 'a')) continue;
                        if (cur->child[c] && cur->child[c]->best != -1) {
                            candidate =
                                max(candidate, depth + 1 + cur->child[c]->best);
                        }
                    }
                }
            }
            if (!broken && depth == (int)words[i].size()) {
                for (int c = 0; c < 26; c++) {
                    if (cur->child[c] && cur->child[c]->best != -1)
                        candidate =
                            max(candidate, depth + 1 + cur->child[c]->best);
                }
            }
            answer[i] = candidate;
        }
        return answer;
    }

    int helper(trie_node* node, const int k) {
        if (node->cnt < k) {
            node->best = -1;
            return -1;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                int child_res = helper(node->child[i], k);
                if (child_res != -1) {
                    res = max(res, 1 + child_res);
                }
            }
        }
        node->best = res;
        return res;
    }

    void insertWord(trie_node* root, const string& word) {
        trie_node* cur = root;
        cur->cnt++;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->child[idx]) {
                cur->child[idx] = new trie_node();
            }
            cur = cur->child[idx];
            cur->cnt++;
        }
    }
};
