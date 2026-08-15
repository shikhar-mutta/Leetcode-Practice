// Link: https://leetcode.com/problems/subsequence-after-one-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) SC: O(1)
//  Approach: since the replaced character can become anything, it just
//  needs to "consume" at least one character of t without needing to
//  match it specifically. Compute pre[i] = leftmost position in t after
//  greedily matching s[0..i-1] as a subsequence (INF if impossible), and
//  suf[i] = rightmost starting position in t after greedily matching
//  s[i..] from the right (-1 if impossible). s can become a subsequence
//  of t via at most one replacement iff either s is already a subsequence
//  (pre[n] <= m), or some split index i has pre[i] < suf[i+1] (a genuine
//  gap to absorb the replaced character).
class Solution
{
public:
    bool func(string &s, string &t, int i, int j, int cnt)
    {

        // Base Case
        if (i >= s.length() || j >= t.length())
        {

            // Still characters left in s but t ended
            if (j == t.length() && i < s.length())
                return false;

            return true;
        }

        // Mismatch after already using replacement
        if (s[i] != t[j] && cnt == 1)
            return false;

        bool tmp;

        // Characters match
        if (s[i] == t[j])
        {

            tmp = func(s, t, i + 1, j + 1, cnt);
        }
        else
        {

            // Either replace current character
            // OR skip current character in t
            tmp = (func(s, t, i + 1, j + 1, 1) || func(s, t, i, j + 1, cnt));
        }

        return tmp;
    }

    bool canMakeSubsequence(string s, string t)
    {

        // Impossible if s is larger
        if (t.length() < s.length())
            return false;

        // Small optimization for equal lengths
        if (t.length() == s.length())
        {

            int cnt = 0;

            for (int i = 0; i < s.length(); i++)
            {

                if (s[i] != t[i])
                    cnt++;

                if (cnt > 1)
                    return false;
            }
        }

        return func(s, t, 0, 0, 0);
    }
};