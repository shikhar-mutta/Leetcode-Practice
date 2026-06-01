// Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int count = 0;
        int charCount[26] = {};

        for (char c : chars)
        { // Count the frequency of each character in the chars string
            charCount[c - 'a']++;
        }

        for (const string &word : words)
        {
            int wordCount[26] = {};
            bool canForm = true;

            for (char c : word)
            {
                wordCount[c - 'a']++;                        // Count the frequency of each character in the word
                if (wordCount[c - 'a'] > charCount[c - 'a']) // Early exit if the word cannot be formed
                {
                    canForm = false;
                    break;
                }
            }

            if (canForm) // If the word can be formed, add its length to the count
            {
                count += word.length();
            }
        }

        return count;
    }
};
