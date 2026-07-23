// Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the string s.
    // SC: O(1), as we are using only a constant amount of extra space
    // Approach:
    //  1. We will iterate through the string s.
    //  2. We will keep track of the number of ones we have seen so far
    //  3. If we encounter a zero, we have two options:
    //     a. We can flip this zero to one, which will increase the number of flips by 1.
    //     b. We can flip all the ones we have seen so far to zeros, which will increase the number of flips by the number of ones we have seen so far.
    //  4. We will take the minimum of these two options and update the number of flips accordingly.
    //  5. At the end, we will return the number of flips
    int minFlipsMonoIncr(string s)
    {
        int n = s.length();
        int count_n_ones = 0;
        int flips = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count_n_ones++;
            }
            else
            {
                flips = min(flips + 1, count_n_ones);
            }
        }
        return flips;
    }
};