// Link: https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n)
    bool rotateString(string s, string goal)
    {
        string temp = s;
        int n = s.size(), i = 0;
        while (i < n)
        {
            if (temp == goal)
                return true;
            temp = temp[n - 1] + temp.substr(0, n - 1);
            i++;
        }
        return false;
    }
};
