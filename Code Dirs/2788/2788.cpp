// Link: https://leetcode.com/problems/split-strings-by-separator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: o(n), SC: o(n)
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (string &s : words)
        {
            string temp;
            for (char &c : s)
            {
                if (c == separator)
                {
                    if (!temp.empty())
                        ans.push_back(temp);
                    temp.clear();
                }
                else
                    temp.push_back(c);
            }
            if (!temp.empty()) // for the last word
                ans.push_back(temp);
        }
        return ans;
    }
};
