// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string reverseWords(string s)
    {
        int n = s.size(), i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};
