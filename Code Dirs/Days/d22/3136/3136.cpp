// Link: https://leetcode.com/problems/valid-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false; // need at least 3 characters
        bool vowel = false, consonant = false;
        string vowels = "aeiouAEIOU";
        for (char c : word)
        {
            if (isalpha((unsigned char)c))
            {
                if (vowels.find(c) != string::npos)
                    vowel = true;
                else
                    consonant = true;
            }
            else if (!isdigit((unsigned char)c))
            {
                return false; // only letters/digits allowed
            }
        }
        return vowel && consonant; // need >=1 vowel and >=1 consonant
    }
};
