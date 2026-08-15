// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(L) per op  SC: O(total chars inserted)
// Approach: 26-way child array per node, isEnd flag marking a complete word
class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    Trie* children[26] = {};
    bool isEnd = false;
    Trie* find(const string& s) {
        Trie* node = this;
        for (char c : s) {
            int i = c - 'a';
            if (!node->children[i]) return nullptr;
            node = node->children[i];
        }
        return node;
    }
};
