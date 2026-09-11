// Link: https://leetcode.com/problems/find-common-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> charCount(26, INT_MAX); // Initialize with max value

        for (const string &word : words)
        {
            vector<int> currentCount(26, 0); // Count characters in the current word
            for (char c : word)
            {
                currentCount[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                charCount[i] = min(charCount[i], currentCount[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) // For each character, add it to the result as many times as it appears in all words
        {
            while (charCount[i] > 0) // Add the character to the result as many times as it appears in all words
            {
                result.push_back(string(1, 'a' + i));
                charCount[i]--;
            }
        }

        return result;
    }
};
