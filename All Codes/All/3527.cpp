// Link: https://leetcode.com/problems/find-the-most-common-response/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total responses * log) SC: O(unique responses)
//  Approach: dedupe each day's responses (a response counts at most once
//  per day), tally frequencies across all days, and return the response
//  with the highest total count, breaking ties lexicographically smallest.
//  We can use a trie to store the responses and their counts, and keep track of the most common response as we insert them.
const int N = 26, M = 1000;
string s = "";
int f = 0;

struct Trie
{
    Trie *next[N];
    int count = 0;

    Trie()
    {
        fill(next, next + N, nullptr);
    }

    void Insert(string &word)
    {
        Trie *node = this;
        for (char c : word)
        {
            int i = c - 'a';
            if (!node->next[i])
                node->next[i] = new Trie();
            node = node->next[i];
        }

        int k = ++node->count;
        if (k > f)
        {
            s = word;
            f = k;
        }
        else if (k == f && word < s)
        {
            s = word;
        }
    }
};

class Solution
{
public:
    string findCommonResponse(vector<vector<string>> &responses)
    {
        const int n = responses.size();
        f = 0, s = "";
        Trie t;

        for (int i = 0; i < n; ++i)
        {
            vector<string> &w = responses[i];
            sort(w.begin(), w.end());
            const int wz = w.size();
            t.Insert(w[0]);

            for (int j = 1; j < wz; ++j)
                if (w[j] != w[j - 1])
                    t.Insert(w[j]);
        }

        return s;
    }
};