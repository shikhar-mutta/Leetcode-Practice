// Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    int canBeTypedWords(string text, string brokenLetters)
    {
        bool broken[26] = {false};
        for (char c : brokenLetters)
            broken[c - 'a'] = true;

        int count = 0;
        string word;
        stringstream ss(text);
        while (ss >> word)
        {
            // a word is typable only if none of its letters are broken
            bool ok = true;
            for (char c : word)
                if (broken[c - 'a'])
                {
                    ok = false;
                    break;
                }
            count += ok;
        }
        return count;
    }
};
