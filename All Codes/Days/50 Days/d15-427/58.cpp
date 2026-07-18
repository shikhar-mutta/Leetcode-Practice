// Link: https://leetcode.com/problems/length-of-last-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int lengthOfLastWord(string s)
    {
        int lastWordLength = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && lastWordLength > 0)
            {
                break;
            }
            else if (s[i] != ' ')
            {
                lastWordLength++;
            }
        }
        return lastWordLength;
    }
};
