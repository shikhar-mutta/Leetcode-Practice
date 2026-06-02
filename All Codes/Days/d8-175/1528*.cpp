// Link: https://leetcode.com/problems/shuffle-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int n = s.size();      // or indices.size()
        string result(n, ' '); // initialize a string of the same length as s with spaces
        for (int i = 0; i < n; i++)
        {
            result[indices[i]] = s[i]; // place the character s[i] at the position specified by indices[i]
        }
        return result;
    }
};
