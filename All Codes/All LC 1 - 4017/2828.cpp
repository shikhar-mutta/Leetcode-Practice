// Link: https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of words, SC: O(1)
    bool isAcronym(vector<string> &words, string s)
    {
        bool isAcronym = true;
        int n = words.size();
        if (s.size() != n)
            return false; // If lengths differ, it can't be an acronym
        for (int i = 0; i < n; i++)
            if (s[i] != words[i][0]) // Compare the i-th character of s with the first character of the i-th word
            {
                isAcronym = false; // If any character doesn't match, it's not an acronym
                break;             // No need to check further
            }
        return isAcronym; // Return the result
    }
};
