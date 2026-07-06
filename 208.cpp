// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    Trie *ch[26] = {};
    bool isEnd = false;

    Trie *find(const string &s)
    {
        Trie *node = this;
        for (char c : s)
        {
            node = node->ch[c - 'a'];
            if (!node)
                return nullptr;
        }
        return node;
    }

public:
    Trie() {}

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            int i = c - 'a';
            if (!node->ch[i])
                node->ch[i] = new Trie();
            node = node->ch[i];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }
};
