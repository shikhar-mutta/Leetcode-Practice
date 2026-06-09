// Link: https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    void reverseString(vector<char> &s)
    {
        int n = (int)s.size();
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - 1 - i]);
    }
};
