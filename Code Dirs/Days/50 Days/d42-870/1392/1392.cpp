// Link: https://leetcode.com/problems/longest-happy-prefix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n). SC: O(n).
// Approach: We can use the KMP algorithm to find the longest prefix which is also a suffix. We can create an array lps which will store the length of the longest prefix which is also a suffix for each index. We can then return the substring of s from 0 to lps[n-1] where n is the length of s.
class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> lps(n, 0);
        int j = 0;
        for (int i = 1; i < n;)
        {

            if (s[i] == s[j])
            {
                j++;
                lps[i] = j;
                i++;
            }
            else
            {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return s.substr(0, lps.back());
    }
};