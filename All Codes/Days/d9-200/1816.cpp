// Link: https://leetcode.com/problems/truncate-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        vector<string> words;
        for (int i = 0; i < s.size(); i++)
        {
            string word;
            while (i < s.size() && s[i] != ' ') // Extract each word from the string
            {
                word += s[i];
                i++;
            }
            words.push_back(word); // Store the extracted word in the vector
        }

        string result; // Construct the truncated sentence by concatenating the first k words
        for (int i = 0; i < k; i++)
        {
            result += words[i];
            if (i != k - 1) // Add a space after each word except the last one
            {
                result += ' ';
            }
        }

        return result;
    }
};
