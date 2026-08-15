// Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int cnt = 0;
        for (const auto &w : words)
        {
            bool ok = true;         // assume the word is consistent until proven otherwise
            for (const auto &c : w) // check each char in the word
            {
                if (allowed.find(c) == string::npos) // char not found in allowed
                {
                    ok = false;
                    break;
                }
            }
            if (ok) // if the word is consistent, increment the count
                cnt++;
        }
        return cnt;
    }
};
