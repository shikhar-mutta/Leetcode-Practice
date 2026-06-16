// Link: https://leetcode.com/problems/vowel-consonant-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int vowelConsonantScore(string s)
    {
        string vowels = "aeiou";
        int v = 0, c = 0;
        for (char ch : s)
        {
            if (!isalpha((unsigned char)ch))
                continue; // ignore spaces/digits
            if (vowels.find(ch) != string::npos)
                v++; // vowel
            else
                c++; // any other letter
        }
        return c > 0 ? v / c : 0; // floor(v/c), or 0 if no consonants
    }
};
