// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1, s2;
        for (const auto &w : word1)
            s1 += w;
        for (const auto &w : word2)
            s2 += w;
        return s1 == s2;
    }
};
