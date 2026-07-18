// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string reverseVowels(string s)
    {
        vector<char> vowels;
        for (char c : s)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowels.push_back(c);
        int j = vowels.size() - 1;
        for (char &c : s)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                c = vowels[j--];
        return s;
    }
};
