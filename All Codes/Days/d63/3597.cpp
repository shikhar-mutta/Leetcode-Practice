// Link: https://leetcode.com/problems/partition-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: Use a trie to store all seen substrings. For each character in the input string, extend the current substring and check if it has been seen before. If not, add it to the trie and start a new segment.
// If it has been seen, continue extending the substring. The number of segments is equal to the number of times we start a new segment.
struct TrieNode
{
    bool isend;
    TrieNode *children[26];
    TrieNode()
    {
        isend = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};
TrieNode pool[100005];
int poolindex = 0;
class Solution
{
public:
    vector<string> partitionString(string s)
    {
        poolindex = 0;
        TrieNode *root = &pool[poolindex++];
        *root = TrieNode();
        vector<string> res;
        string temp = "";
        TrieNode *node = root;
        for (auto &ch : s)
        {
            temp += ch;
            if (!node->children[ch - 'a'])
            {
                node->children[ch - 'a'] = &pool[poolindex++];
                *node->children[ch - 'a'] = TrieNode();
                res.push_back(temp);
                temp = "";
                node = root;
            }
            else
            {
                node = node->children[ch - 'a'];
            }
        }
        return res;
    }
};