// Link: https://leetcode.com/problems/trim-trailing-vowels/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string trimTrailingVowels(string s)
    {
        string vowels = "aeiouAEIOU";
        // drop characters from the end while they are vowels
        while (!s.empty() && vowels.find(s.back()) != string::npos)
            s.pop_back();
        return s;
    }
};
