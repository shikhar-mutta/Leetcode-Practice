// Link: https://leetcode.com/problems/stream-of-characters/description/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class StreamChecker {
    TrieNode* root;
    string stream;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& w : words) {
            TrieNode* node = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int idx = w[i] - 'a';
                if (!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    }

    bool query(char letter) {
        stream += letter;
        TrieNode* node = root;
        for (int i = stream.size() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd) return true;
        }
        return false;
    }
};
