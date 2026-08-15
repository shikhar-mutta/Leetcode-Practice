// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26] = {nullptr};
    bool isEOW = false;
    bool contains(char c)
    {
        return children[c - 'a'] != nullptr;
    }
    void put(char c, TrieNode *node)
    {
        children[c - 'a'] = node;
    }
    void setEnd()
    {
        isEOW = true;
    }
    bool isLeaf()
    {
        return isEOW;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != nullptr)
            {
                delete children[i];
            }
        }
    }
};
class Trie
{
    TrieNode *root = new TrieNode();

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        // walk a local cursor, not root itself — reassigning root would lose the actual root after the first call
        TrieNode *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contains(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->children[word[i] - 'a'];
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contains(word[i]))
            {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isLeaf();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contains(prefix[i]))
            {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};
