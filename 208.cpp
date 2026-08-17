// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        bool eow;
        TrieNode *arr[26];
    };

    TrieNode *root;

public:
    // Constructor
    Trie() { root = new TrieNode(); }

    void insert(string word)
    {
        TrieNode *node = root;
        for (auto ch : word)
        {
            if (node->arr[ch - 'a'] == nullptr)
                node->arr[ch - 'a'] = new TrieNode();
            node = node->arr[ch - 'a'];
        }
        node->eow = true;
    }

    bool search(string word)
    {
        TrieNode *nd = root;
        for (auto ch : word)
        {
            if (nd->arr[ch - 'a'] == nullptr)
                return false;
            nd = nd->arr[ch - 'a'];
        }
        return nd->eow;
    }

    bool startsWith(string prefix)
    {
        TrieNode *nd = root;
        for (auto ch : prefix)
        {
            if (nd->arr[ch - 'a'] == nullptr)
                return false;
            nd = nd->arr[ch - 'a'];
        }
        return true;
    }
};