// Link: https://leetcode.com/problems/long-pressed-name/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) . SC: O(1) .
    bool isLongPressedName(string name, string typed)
    {
        int n = name.size(), m = typed.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (name[i] == typed[j]) // Correct char, move both pointer
            {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
                j++; // miss typed char
            else     // Wrong char, return false
                return false;
        }
        while (j > 0 && j < m && typed[j] == typed[j - 1])
            j++; // if there remaining char is same as last char of name, then it is also valid
        return i == n && j == m;
    };
};