// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string.
    // SC: O(1) for storing the result.
    // Approach:
    //       1. Count the number of 'a's in the string.
    //       2. Iterate through the string and for each character, update the count of 'a's and 'b's.
    //       3. Calculate the minimum deletions required to make the string balanced by taking the minimum of the current result and the sum of remaining 'a's and 'b's.
    //       4. Return the result.
    int minimumDeletions(string s)
    {
        int n = s.size(), res = n;
        int a = 0, b = 0;

        for (auto &c : s)
            a += c & 1; //'a' = 97 (odd)

        for (auto &c : s)
        {
            a -= c & 1;
            res = min(res, a + b);
            b += ~c & 1; //'b' = 98 (even)
        }

        return res;
    }
};