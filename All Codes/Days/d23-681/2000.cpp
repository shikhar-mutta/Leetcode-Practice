// Link: https://leetcode.com/problems/reverse-prefix-of-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the string. SC: O(1)
    string reversePrefix(string word, char ch)
    {
        // reverse the prefix up to (and including) the first ch; unchanged if absent
        size_t pos = word.find(ch);
        if (pos != string::npos)
            reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};
