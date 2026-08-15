// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(L) addWord, O(26^L) worst-case search (with '.')  SC: O(total chars inserted)
// Approach: 26-way TrieNode array; search does DFS backtracking, branching into all 26 children on '.'
class WordDictionary {
public:
    WordDictionary() {}

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new WordDictionary();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0);
    }

private:
    WordDictionary* children[26] = {};
    bool isEnd = false;

    bool dfs(const string& word, int idx) {
        if (idx == (int)word.size()) return isEnd;
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; i++)
                if (children[i] && children[i]->dfs(word, idx + 1)) return true;
            return false;
        }
        int i = c - 'a';
        return children[i] && children[i]->dfs(word, idx + 1);
    }
};
