// Link: https://leetcode.com/problems/word-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w)
            words.push_back(w);

        int n = (int)pattern.size(), m = (int)words.size();

        if (n != m)
            return false;

        map<char, string> mp;
        map<string, char> rev;
        for (int i = 0; i < n; i++)
        {
            char c = pattern[i];
            string word = words[i];
            if (mp.count(c) && mp[c] != word)
                return false;
            if (rev.count(word) && rev[word] != c)
                return false;
            mp[c] = word;
            rev[word] = c;
        }
        return true;
    }
};
