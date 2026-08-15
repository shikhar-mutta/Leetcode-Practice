// Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    string makeFancyString(string s)
    {
        int j = 0;
        if (s.size() < 3)
            return s;
        for (int i = 0; i < s.size() - 2; i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                continue;
            }
            else
            {
                s[j] = s[i];
                j++;
            }
        }
        s[j] = s[s.size() - 2];
        j++;
        s[j] = s[s.size() - 1];
        j++;

        s.resize(j);
        return s;
    }
};