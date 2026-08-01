// Link: https://leetcode.com/problems/longest-common-suffix-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n * m)
// Approach: Build a trie of the reversed words in wordsContainer. Each node in the trie stores the index of the word with the longest length that passes through that node. For each query, traverse the trie using the characters of the reversed query string and return the stored index at the last node reached.
struct Trie
{
    array<Trie *, 26> children;
    int ans = 0;
};

void insert(Trie *trie, int i, vector<string> &words)
{
    auto &w = words[i];
    auto comp = words[trie->ans].size() <=> w.size();
    if (comp > 0)
    {
        trie->ans = i;
    }
    else if (comp == 0)
    {
        trie->ans = min(trie->ans, i);
    }
    for (int j = 0; j < w.size(); ++j)
    {
        int c = w[w.size() - j - 1] - 'a';
        if (!trie->children[c])
        {
            auto next = new Trie();
            trie->children[c] = next;
            next->ans = i;
            return;
        }
        else
        {
            trie = trie->children[c];
            auto &curr = words[trie->ans];
            if (curr.size() - 1 > j)
            {
                int next_curr_char = curr[curr.size() - j - 2] - 'a';
                if (trie->children[next_curr_char] == nullptr)
                {
                    auto next_curr_trie = new Trie();
                    next_curr_trie->ans = trie->ans;
                    trie->children[next_curr_char] = next_curr_trie;
                }
            }
            comp = curr.size() <=> w.size();
            if (comp < 0)
            {
                continue;
            }
            if (comp > 0)
            {
                trie->ans = i;
            }
            trie->ans = min(trie->ans, i);
        }
    }
}

int get(Trie *trie, string &s)
{
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int c = s[i] - 'a';
        if (trie->children[c] == nullptr)
        {
            break;
        }
        trie = trie->children[c];
    }

    return trie->ans;
}

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer,
                              vector<string> &wordsQuery)
    {
        Trie *trie = new Trie();
        for (int i = 0; i < wordsContainer.size(); ++i)
        {
            insert(trie, i, wordsContainer);
        }

        vector<int> ans(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); ++i)
        {
            ans[i] = get(trie, wordsQuery[i]);
        }

        return ans;
    }
};
