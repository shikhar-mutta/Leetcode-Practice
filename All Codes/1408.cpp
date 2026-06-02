// Link: https://leetcode.com/problems/string-matching-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> ans;
        int n = words.size();
        // no sort needed — distinct words of equal length can never be substrings of each other

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && words[j].find(words[i]) != string::npos)
                { // words[i] is a substring of words[j]
                    ans.push_back(words[i]);
                    break; // found one match, no need to check further
                }

        return ans;
    }
};
