// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        unordered_map<int, TrieNode*> children;
        long long cnt = 0;
    };

    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        long long ans = 0;
        for (auto& w : words) {
            int L = w.size();
            // query
            TrieNode* cur = root;
            for (int i = 0; i < L && cur; i++) {
                int key = (w[i] - 'a') * 26 + (w[L-1-i] - 'a');
                auto it = cur->children.find(key);
                if (it == cur->children.end()) { cur = nullptr; break; }
                cur = it->second;
                ans += cur->cnt;
            }
            // insert
            cur = root;
            for (int i = 0; i < L; i++) {
                int key = (w[i] - 'a') * 26 + (w[L-1-i] - 'a');
                if (!cur->children.count(key)) cur->children[key] = new TrieNode();
                cur = cur->children[key];
            }
            cur->cnt++;
        }
        return ans;
    }
};
