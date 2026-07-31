// Link: https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) where n is the length of s and m is the length of pattern
// SC: O(n + m) where n is the length of s and m is the length of pattern
// Approach: We can use the Z algorithm to find the longest prefix of the pattern that matches a substring of s. We can then reverse both the pattern and s and use the Z algorithm again to find the longest suffix of the pattern that matches a substring of s. We can then check if the sum of the lengths of the longest prefix and suffix is greater than or equal to the length of the pattern minus 1. If it is, we return the starting index of the substring in s that matches the pattern. If not, we return -1.
class Solution
{
public:
    vector<int> Z(string s)
    {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
            else
            {
                int k = i - l;
                if (z[k] < r - i + 1)
                {
                    z[i] = z[k];
                }
                else
                {
                    l = i;
                    while (r < n && s[r - l] == s[r])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
    int minStartingIndex(string s, string pattern)
    {
        int n = s.size(), m = pattern.size();
        if (m > n)
            return -1;
        vector<int> z1 = Z(pattern + '$' + s);
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        vector<int> z2 = Z(pattern + '$' + s);
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        reverse(z2.begin() + m + 1, z2.end());
        for (int i = m + 1; i < n + m + 1; i++)
        {
            int start = i - m - 1;
            if (start > n - m)
                break;
            int prefix = z1[i];
            int suffix = z2[i + m - 1];
            if (prefix + suffix >= m - 1)
                return start;
        }
        return -1;
    }
};