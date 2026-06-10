// Link: https://leetcode.com/problems/detect-capital/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool detectCapitalUse(string word)
    {
        if (isupper(word[0]) && isupper(word[1]))
        {
            for (int i = 2; i < word.size(); i++)
            {
                if (!isupper(word[i]))
                    return false;
            }
        }
        else
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }

        return true;
    }
};
