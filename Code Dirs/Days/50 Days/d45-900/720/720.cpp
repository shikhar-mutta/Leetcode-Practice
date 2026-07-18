// Link: https://leetcode.com/problems/longest-word-in-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m). SC: O(n * m).
// Approach: Use a Trie data structure to store all the words. Then, for each word, check if all its prefixes are present in the Trie. If they are, compare the length and lexicographical order to find the longest word with all prefixes present.
class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
            isEnd = false;
        }
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(string &word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';

            if (curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    bool serchAllPrefix(string &word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';

            curr = curr->child[idx];

            if (curr->isEnd == false)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie tries;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            tries.insert(word);
        }

        string ans = "";

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if (tries.serchAllPrefix(word) == true)
            {
                if (word.size() > ans.size())
                {
                    ans = word;
                }
                else if (word.size() == ans.size() && word < ans)
                {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
