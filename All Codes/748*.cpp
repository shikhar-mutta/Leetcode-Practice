// Link: https://leetcode.com/problems/shortest-completing-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        // need[i] = number of times we need character 'a'+i
        int need[26] = {};
        // Count the characters in licensePlate
        for (char c : licensePlate)
            if (isalpha(c))
                need[tolower(c) - 'a']++;

        string ans;
        for (auto &w : words)
        { // have[i] = number of times we have character 'a'+i in w
            int have[26] = {};
            for (char c : w)
                have[c - 'a']++;

            bool ok = true;
            // have[i] < need[i] means w does not have enough of character 'a'+i
            for (int i = 0; i < 26; i++)
                if (have[i] < need[i])
                {
                    ok = false;
                    break;
                }
            
            if (ok && (ans.empty() || w.size() < ans.size()))
                ans = w;
        }
        return ans;
    }
};
