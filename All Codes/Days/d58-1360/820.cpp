// Link: https://leetcode.com/problems/short-encoding-of-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), SC: O(n * m)
    //  Approach:
    //  1. We can use an unordered_set to keep track of the words that are present in the input vector. We can then iterate through the input vector and for each word, we can generate all possible suffixes of the word and remove them from the unordered_set. This way, we will be left with only the words that are not suffixes of any other word in the input vector.
    //  2. Finally, we can iterate through the unordered_set and calculate the total length of the words in the set, adding 1 for each word to account for the '#' character that will be added to the end of each word in the final encoding. We can return this total length as the answer.
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> wordSet(words.begin(), words.end());
        for (const string &w : words)
            for (int i = 1; i < (int)w.size(); i++)
                wordSet.erase(w.substr(i));

        int total = 0;
        for (const string &w : wordSet)
            total += w.size() + 1;
        return total;
    }
};
