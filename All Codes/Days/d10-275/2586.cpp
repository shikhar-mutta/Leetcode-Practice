// Link: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; ++i)
        {
            string &word = words[i];
            if (isVowel(word.front()) && isVowel(word.back()))
            {
                ++count;
            }
        }
        return count;
    }
};
