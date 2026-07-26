// Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) – for each of n positions, s.find() is called up to 3 times
//     (break after count > 2), each O(n), giving O(n^2) total
// SC: O(n)   – sub string grows up to length n in the worst case
// Approach: A "special" substring is one made of a single repeated character.
// Scan left to right, maintaining the current run sub (same char as previous,
// else reset to current char). For each run-prefix sub, count occurrences in s
// via s.find(); if count > 2 (i.e. ≥ 3 occurrences), update ans with sub's
// length. Early exit after finding the 3rd occurrence for efficiency.
class Solution
{
public:
    int maximumLength(string s)
    {
        int ans = -1;
        int n = s.length();
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            if (sub.length() == 0)
                sub += s[i];
            else if (sub[0] == s[i])
                sub += s[i];
            else
                sub = s[i];
            auto pos = s.find(sub, 0);
            int count = 0;
            while (pos != string::npos)
            {
                count++;
                if (count > 2)
                {
                    ans = max(ans, int(sub.length()));
                    break;
                }
                pos = s.find(sub, pos + 1);
            }
        }
        return ans;
    }
};