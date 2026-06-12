// Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m), where n and m are the lengths of s1 and s2 respectively.
    // SC: O(n + m), for storing the words in the unordered_map and the
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        stringstream ss(s1 + " " + s2);
        string word;

        while (ss >> word)
            mp[word]++;

        for (auto &[k, v] : mp)
            if (v == 1)
                ans.push_back(k);

        return ans;
    }
};
