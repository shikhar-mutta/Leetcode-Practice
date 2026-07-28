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
class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class StreamChecker {
    TrieNode* root;
    string buffer;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& w : words) {
            TrieNode* node = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int c = w[i] - 'a';
                if (!node->children[c]) node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isEnd = true;
        }
    }

    bool query(char letter) {
        buffer += letter;
        TrieNode* node = root;
        for (int i = buffer.size() - 1; i >= 0; i--) {
            int c = buffer[i] - 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
            if (node->isEnd) return true;
        }
        return false;
    }
};
