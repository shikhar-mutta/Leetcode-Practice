// Link: https://leetcode.com/problems/rearrange-words-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) for sorting the words.
    // SC: O(n) for storing the words.
    //  Approach:
    //  1. Split the sentence into words.
    //  2. Sort the words based on their lengths.
    string arrangeWords(string text)
    {
        text[0] = tolower(text[0]);
        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w)
            words.push_back(w);
        // stable: equal-length words keep their original order
        stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                    { return a.size() < b.size(); });
        string res;
        for (auto &word : words)
        {
            if (!res.empty())
                res += " ";
            res += word;
        }
        res[0] = toupper(res[0]);
        return res;
    }
};
