// Link: https://leetcode.com/problems/lexicographically-smallest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string makeSmallestPalindrome(string s)
    {
        // for each mirrored pair, set both chars to the smaller one (lexicographically smallest)
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            s[l] = s[r] = min(s[l], s[r]); // set both chars to the smaller one
            l++;
            r--;
        }
        return s;
    }
};
