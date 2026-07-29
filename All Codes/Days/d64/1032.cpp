// Link: https://leetcode.com/problems/stream-of-characters/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(maxWordLen) per query  SC: O(sum of word lengths)
// Approach: build a trie of the REVERSED words. Maintain a growing
// buffer of the stream's characters; on each query, walk the trie
// starting from the most recent character backward through the buffer,
// returning true as soon as a word-end marker is hit (meaning some
// suffix of the stream matches a dictionary word).
class StreamChecker
{
    struct Node
    {
        array<int, 26> next;
        bool word;
        Node() : word(false) { next.fill(-1); }
    };
    vector<Node> trie;
    deque<char> hist;
    int maxLen;

public:
    StreamChecker(vector<string> &words) : maxLen(0)
    {
        trie.emplace_back();
        int totalChars = 1;
        for (const auto &w : words)
        {
            maxLen = max(maxLen, (int)w.size());
            totalChars += w.size();
        }
        trie.reserve(totalChars);
        for (const auto &w : words)
        {
            int node = 0;
            for (int i = (int)w.size() - 1; i >= 0; --i)
            {
                int c = w[i] - 'a';
                if (trie[node].next[c] == -1)
                {
                    trie[node].next[c] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node].next[c];
            }
            trie[node].word = true;
        }
    }

    bool query(char letter)
    {
        hist.push_back(letter);
        if ((int)hist.size() > maxLen)
        {
            hist.pop_front();
        }
        int node = 0;
        for (auto it = hist.rbegin(); it != hist.rend(); ++it)
        {
            int c = *it - 'a';
            int nxt = trie[node].next[c];
            if (nxt == -1)
            {
                return false;
            }
            node = nxt;
            if (trie[node].word)
            {
                return true;
            }
        }
        return false;
    }
};