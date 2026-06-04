// Link: https://leetcode.com/problems/odd-string-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddString(vector<string> &words)
    {
        unordered_map<string, vector<int>> mp;
        int n = words.size();
        for (int i = 0; i < n; i++)
        { // Calculate the difference string for the current word
            string diff = "";
            int m = words[i].size();
            for (int j = 1; j < m; j++) // find diff & add to map
                diff += to_string(words[i][j] - words[i][j - 1]) + ",";
            mp[diff].push_back(i); // push Index of the word in the map
        }
        for (auto &x : mp)
            if (x.second.size() == 1)
                return words[x.second[0]];
        return "";
    }
};
