// Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: use substr method of String. TC: O(n * m), m is length of prefix. SC: O(1)
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (const string &word : words)
        { // Check if the prefix of the word matches the given prefix
            if (word.substr(0, pref.size()) == pref)
            {
                count++;
            }
        }
        return count;
    }
};
