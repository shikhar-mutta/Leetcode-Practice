// Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        int index = 1;
        while (ss >> word)
        {
            if (word.find(searchWord) == 0)
                return index;
            ++index;
        }
        return -1;
    }
};
