// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;
        for (string pattern : patterns)
        {
            // to find substring in word
            if (word.find(pattern) != string::npos)
            { // Check if the pattern is a substring of word
                count++;
            }
        }
        return count;
    }
};
