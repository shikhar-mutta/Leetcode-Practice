// Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m) where n is the size of the dictionary and m is the size of the string s.
    // SC: O(1).
    // Approach: For each string in the dictionary, we check if it can be formed by deleting some characters from the string s. We use two pointers to traverse both strings and check for matches. If a match is found, we move the pointer of the dictionary string forward. If we reach the end of the dictionary string, it means it can be formed from s. We keep track of the longest valid string found so far and return it at the end.
    bool isOk(string &str, string &s)
    {
        int i = 0, j = 0;

        while (i < s.size() && j < str.size())
        {
            if (s[i] == str[j])
                j++;
            i++;
        }

        return j == str.size();
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        int maxi = 0;
        string newStr = "";
        for (string str : dictionary)
        {
            int se = str.size();
            if (isOk(str, s))
                if (str.size() > maxi || (str.size() == maxi && str < newStr))
                {
                    newStr = str;
                    maxi = str.size();
                }
        }
        return newStr;
    }
};