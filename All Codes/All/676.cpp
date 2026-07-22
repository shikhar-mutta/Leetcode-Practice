// Link: https://leetcode.com/problems/implement-magic-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of words in the dictionary and m is the length of the search word. In the worst case, we may have to check all words in the dictionary to see if they can be formed by changing exactly one character in the search word.
// SC: O(n) for storing the words in the vector.
// Approach:
// 1. We use a vector to store the words in the dictionary.
// 2. The buildDict function simply assigns the input dictionary to the words vector.
// 3. The search function iterates through all the words in the dictionary and checks if they can be formed by changing exactly one character in the search word. If they can, we return true. If we finish checking all words and none can be formed, we return false.
// 4. Finally, we return true if we find a word that can be formed by changing exactly one character in the search word, otherwise we return false.
class MagicDictionary
{
    vector<string> words;

public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        words = dictionary;
    }

    bool search(string searchWord)
    {
        for (auto &w : words)
        {
            if (w.size() != searchWord.size())
                continue;
            int diff = 0;
            for (size_t i = 0; i < w.size() && diff <= 1; i++)
            {
                if (w[i] != searchWord[i])
                    diff++;
            }
            if (diff == 1)
                return true;
        }
        return false;
    }
};
