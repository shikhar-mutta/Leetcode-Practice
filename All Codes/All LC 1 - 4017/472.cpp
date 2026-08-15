// Link: https://leetcode.com/problems/concatenated-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum(len^2))  SC: O(sum(len))
//  Approach: use a trie to store all words, then for each word check if it can be
//  split into at least two other words in the trie.
//  To check if a word can be split, we maintain a list of indices into the trie
//  that we are currently at. For each character, we advance all indices in the list
//  and if any of them is terminal, we add the root to the list. At the end, we check if there are at least two terminal nodes in the list.
struct trie
{
    static array<int, 26> V[10000 * 30];
    static bool is_word[10000 * 30];
    int sz_v;

    int new_node()
    {
        memset(V[sz_v].data(), -1, 26 * sizeof(int));
        is_word[sz_v] = false;
        return sz_v++;
    }

    trie() : sz_v(0) { new_node(); }

    void insert(const string &w)
    {
        int node = 0; // start at the root
        for (char c : w)
        {
            const int cc = c - 'a';
            if (V[node][cc] == -1)
                V[node][cc] = new_node();
            node = V[node][cc];
        }
        is_word[node] = true;
    }

    bool is_concat(const string &w)
    {
        vector<int> inxs{0};
        for (char c : w)
        {
            const int cc = c - 'a';
            // if any of them is terminal, add the root!
            for (int node : inxs)
                if (is_word[node])
                {
                    inxs.push_back(0);
                    break;
                }

            for (int i = 0; i < inxs.size();)
            {
                const int node = V[inxs[i]][cc];
                if (node == -1)
                {
                    inxs[i] = inxs.back();
                    inxs.pop_back();
                }
                else
                {
                    inxs[i] = node;
                    i++;
                }
            }
        }

        // finally, we need at least two terminal nodes
        int num_terminal = 0;
        for (int node : inxs)
            num_terminal += is_word[node];
        return num_terminal >= 2;
    }
};

array<int, 26> trie::V[10000 * 30];
bool trie::is_word[10000 * 30];

class Solution
{
public:
    vector<string>
    findAllConcatenatedWordsInADict(const vector<string> &words)
    {
        trie T;
        for (const auto &w : words)
            T.insert(w);
        vector<string> ans;
        for (const auto &w : words)
            if (T.is_concat(w))
                ans.push_back(w);
        return ans;
    }
};