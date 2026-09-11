// Link: https://leetcode.com/problems/count-binary-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    int countBinarySubstrings(string s)
    {

        int prev = 0, curr = 1, ans = 0, n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1]) // inc count of group of same char
                curr++;
            else
            {
                ans += min(prev, curr);
                prev = curr; // update prev to count of last char group
                curr = 1;    // reset count for new char group
            }
        }

        ans += min(prev, curr); // for the last group, as loop ends without checking it

        return ans;
    }
};