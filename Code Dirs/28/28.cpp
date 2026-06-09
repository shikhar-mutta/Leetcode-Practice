// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(1)
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j])
                j++;

            if (j == m)
                return i;
        }
        return -1;
    };
};
