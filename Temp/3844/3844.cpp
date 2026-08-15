// Link: https://leetcode.com/problems/longest-almost-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
//  Approach: for every center (odd single-char, even double-char, even
//  double-char treated as an empty core when its two chars mismatch),
//  expand outward while characters match to find the maximal pure
//  palindrome core. Beyond that core, try using the one allowed deletion
//  on the very next left or right character, then keep expanding in
//  lockstep — this correctly captures both "delete a boundary character"
//  and "delete a character strictly inside" cases, since after the single
//  skip the remaining comparison must match perfectly like a normal
//  palindrome expansion.
class Solution
{
public:
    int fn(string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        int curr = r - l - 1;
        int val1 = 0, val2 = 0;
        if (l < 0)
            val1 = curr + 1;
        if (r > s.size() - 1)
            val2 = curr + 1;
        int l1 = l, r1 = r;
        r1++;
        while (l1 >= 0 && r1 < s.size() && s[l1] == s[r1])
        {
            l1--;
            r1++;
        }
        val1 = max(val1, r1 - l1 - 1);
        int l2 = l, r2 = r;
        l2--;
        while (l2 >= 0 && r2 < s.size() && s[l2] == s[r2])
        {
            l2--;
            r2++;
        }
        val2 = max(val2, r2 - l2 - 1);
        return max(val1, val2);
    }
    bool checkpal(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    int almostPalindromic(string s)
    {
        int n = s.size();
        if (checkpal(s))
            return n;
        int ans = 2;
        for (int i = 0; i < n - 1; i++)
        {
            int x = fn(s, i, i);
            int y = fn(s, i, i + 1);
            ans = max({ans, x, y});
        }
        return ans;
    }
};
