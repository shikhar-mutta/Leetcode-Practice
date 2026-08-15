// Link: https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* child[26] = {};
    int passCount = 0;
    int endCount = 0;

    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new Trie();
            node = node->child[idx];
            node->passCount++;
        }
        node->endCount++;
    }

    Trie* find(const string& word) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) return nullptr;
            node = node->child[idx];
        }
        return node;
    }

    int countWordsEqualTo(string word) {
        Trie* node = find(word);
        return node ? node->endCount : 0;
    }

    int countWordsStartingWith(string prefix) {
        Trie* node = find(prefix);
        return node ? node->passCount : 0;
    }

    void erase(string word) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            node = node->child[idx];
            node->passCount--;
        }
        node->endCount--;
    }
};
