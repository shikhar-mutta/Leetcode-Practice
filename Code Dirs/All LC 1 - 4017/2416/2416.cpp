// Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        int children[26];
        int count = 0;
        TrieNode() { fill(begin(children), end(children), -1); }
    };
    vector<TrieNode> trie;

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie.emplace_back();
        for (auto &w : words) {
            int cur = 0;
            for (char c : w) {
                int idx = c - 'a';
                if (trie[cur].children[idx] == -1) {
                    trie[cur].children[idx] = trie.size();
                    trie.emplace_back();
                }
                cur = trie[cur].children[idx];
                trie[cur].count++;
            }
        }

        vector<int> ans;
        for (auto &w : words) {
            int cur = 0;
            int total = 0;
            for (char c : w) {
                cur = trie[cur].children[c - 'a'];
                total += trie[cur].count;
            }
            ans.push_back(total);
        }
        return ans;
    }
};
