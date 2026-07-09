// Link: https://leetcode.com/problems/find-and-replace-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m * k), where n is the length of s, m is the number of replacements, and k is the average length of sources[i]
    // SC: O(n + m * k), where n is the length of s, and m is the number of replacements, and k is the average length of sources[i]
    //  Approach:
    //  1. Create a vector of vectors to store the replacement indices starting at each index
    //  2. Iterate through the string s and check if there is a replacement starting at the current index
    //  3. If there is a replacement, add the target string to the result and skip the length of the source string
    //  4. If there is no replacement, add the current character to the result and move to the next index
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        int n = s.size();
        vector<vector<int>> ops(n); // ops[i] = replacement indices starting at i
        for (int j = 0; j < (int)indices.size(); j++)
            ops[indices[j]].push_back(j);

        string res;
        int i = 0;
        while (i < n)
        {
            int hit = -1;
            for (int j : ops[i])
                if (s.compare(i, sources[j].size(), sources[j]) == 0)
                {
                    hit = j;
                    break;
                }
            if (hit != -1)
            {
                res += targets[hit];
                i += sources[hit].size();
            }
            else
                res += s[i++];
        }
        return res;
    }
};
