// Link: https://leetcode.com/problems/merge-strings-alternately/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n1 + n2). SC: O(n1 + n2).
    string mergeAlternately(string word1, string word2)
    {
        string res;
        int i = 0, n1 = word1.size(), n2 = word2.size();
        // interleave while both have characters
        for (; i < n1 && i < n2; i++)
        {
            res += word1[i];
            res += word2[i];
        }
        // append whichever string still has a tail
        res += word1.substr(i);
        res += word2.substr(i);
        return res;
    }
};
