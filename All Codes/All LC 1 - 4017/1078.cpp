// Link: https://leetcode.com/problems/occurrences-after-bigram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<string> findOcurrences(string text, string first, string second)
    {
        stringstream ss(text); // Create a stringstream object to read words from the input text
        string word, prev1, prev2;
        vector<string> ans;
        while (ss >> word) // Take each word from the stringstream
        {
            if (prev1 == first && prev2 == second)
            {
                ans.push_back(word);
            }
            prev1 = prev2;
            prev2 = word;
        }
        return ans;
    };
};