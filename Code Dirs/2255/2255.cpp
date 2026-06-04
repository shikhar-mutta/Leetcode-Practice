// Link: https://leetcode.com/problems/count-prefixes-of-a-given-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Check if each word is a prefix of the string s.
    // TC: O(N * M) where N is the number of words and M is the
    // SC: O(1) as we are using only a constant amount of space.
    int countPrefixes(vector<string> &words, string s)
    {
        int cnt = 0;
        for (auto it : words)
        {
            if (s.substr(0, it.size()) == it)
                cnt++;
        }
        return cnt;
    }
};
