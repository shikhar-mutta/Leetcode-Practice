// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) - The addWord function has a time complexity of O(n), where n is the length of the word being added. The search function also has a time complexity of O(n) in the worst case, where n is the length of the word being searched. In the case of a search with a wildcard character '.', the time complexity can be higher due to the need to explore multiple branches in the trie.
// SC: O(m) - The space complexity of the WordDictionary class is O(m), where m is the total number of characters in all the words added to the data structure. Each unique character in the words contributes to the space used by the trie nodes. The use of a bitmask to represent the presence of characters in each trie node helps optimize space usage, as it allows for efficient storage of character information without needing to store all possible characters explicitly.
// Approach:
// 1. We define a TrieNode class that represents a node in the trie. Each node contains an array of 26 elements to represent the 26 lowercase English letters, a boolean flag wordEnd to indicate if a word ends at that node, and a bitmask to efficiently track which characters are present in the node's children.
// 2. The WordDictionary class contains a static vector of TrieNode objects to represent the trie. The constructor initializes the trie by reserving space for a large number of nodes and clearing any existing nodes. The addWord function adds a word to the trie by traversing the trie and creating new nodes as needed, updating the bitmask to reflect the presence of characters. The search function checks if a word exists in the trie, handling both exact matches and wildcard searches using the '.' character. It recursively explores the trie based on the characters in the word, using the bitmask to efficiently determine which branches to explore when encountering a wildcard.
class alignas(64) TrieNode
{
public:
    uint16_t arr[26];
    bool wordEnd{false};
    uint32_t mask{0};
};

class WordDictionary
{
    inline static vector<TrieNode> trie{};

public:
    WordDictionary()
    {
        static bool init = (trie.reserve(500002), true);
        trie.clear();
        trie.emplace_back();
    }

    void addWord(const string &word)
    {
        uint32_t level = 0;
        for (char c : word)
        {
            uint32_t idx = c - 'a';
            if ((trie[level].mask & (1 << idx)) == 0)
            {
                trie[level].arr[idx] = trie.size();
                trie[level].mask |= (1 << idx);
                trie.emplace_back();
            }
            level = trie[level].arr[idx];
        }
        trie[level].wordEnd = true;
    }

    bool search(uint32_t level, string_view word)
    {
        if (word.empty())
            return trie[level].wordEnd;
        char c = word.front();
        uint32_t idx = c - 'a';
        if (c != '.')
        {
            if (trie[level].mask & (1 << idx))
                return search(trie[level].arr[idx], word.substr(1));
        }
        else
        {
            uint32_t m = trie[level].mask;
            while (m)
            {
                uint32_t idx = std::countr_zero(m);
                if (search(trie[level].arr[idx], word.substr(1)))
                    return true;
                m = m & (m - 1);
            }
        }
        return false;
    }

    bool search(const string &word)
    {
        return search(0, word);
    }
};