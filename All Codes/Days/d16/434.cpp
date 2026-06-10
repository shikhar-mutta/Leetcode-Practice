// Link: https://leetcode.com/problems/number-of-segments-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countSegments(string s)
    {
        int count = 0, n = s.size(), i = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i < n)
                count++;
            while (i < n && s[i] != ' ')
                i++;
        }
        return count;
    }
};
