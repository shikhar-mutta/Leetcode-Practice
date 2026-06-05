// Link: https://leetcode.com/problems/find-words-containing-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> result;
        for (int i = 0; i < words.size(); ++i)
            if (words[i].find(x) != string::npos)
                result.push_back(i);
        return result;
    }
};
