// Link: https://leetcode.com/problems/sorting-the-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    string sortSentence(string s)
    {
        map<int, string> mp;
        string word;
        for (char c : s)
        {
            if (c == ' ')
            {
                int pos = word.back() - '0';
                word.pop_back();
                mp[pos] = word;
                word = "";
            }
            else
            {
                word += c;
            }
        }
        int pos = word.back() - '0';
        word.pop_back();
        mp[pos] = word;

        string result;
        for (auto &p : mp)
        {
            result += p.second + " ";
        }
        result.pop_back();
        return result;
    }
};
