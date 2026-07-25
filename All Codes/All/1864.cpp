// Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //   1. Count the number of '1's and '0's in the string.
    //   2. If the difference between the counts of '1's and '0's is greater than 1, return -1 (impossible to make alternating).
    //  3. Define a lambda function to calculate the number of swaps needed to make the string alternating starting with a given character ('0' or '1').
    //  4. If there are more '1's than '0's, call the lambda function with '1' as the starting character.
    //  5. If there are more '0's than '1's, call the lambda function with '0' as the starting character.
    //  6. If the counts of '1's and '0's are equal, return the minimum of the two possible starting characters.
    int minSwaps(string s)
    {
        int n = s.size(), ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;
        if (abs(ones - zeros) > 1)
            return -1;

        auto cost = [&](char start)
        {
            int mismatch = 0;
            char c = start;
            for (char ch : s)
            {
                if (ch != c)
                    ++mismatch;
                c ^= 1; // toggle '0' <-> '1'
            }
            return mismatch / 2;
        };

        if (ones > zeros)
            return cost('1');
        if (zeros > ones)
            return cost('0');
        return min(cost('0'), cost('1'));
    }
};