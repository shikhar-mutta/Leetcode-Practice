// Link: https://leetcode.com/problems/number-of-unique-good-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: Use dynamic programming to count the number of unique good subsequences. We can keep track of the number of good subsequences that end with '0' and the number of good subsequences that end with '1'. We can also keep track of whether we have seen a '0' in the string. If we have seen a '0', we can add 1 to the count of good subsequences to account for the empty subsequence. Finally, we return the sum of the counts of good subsequences that end with '0' and '1', plus 1 if we have seen a '0'.
class Solution
{
public:
    int mod = 1e9 + 7;
    int numberOfUniqueGoodSubsequences(string binary)
    {
        bool haszero = false;
        int end0 = 0;
        int end1 = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == '1')
            {
                end1 = (end0 + end1 + 1) % mod;
            }
            else
            {
                haszero = true;
                end0 = (end0 + end1) % mod;
            }
        }
        if (haszero)
            return (end0 + end1 + 1) % mod;
        else
            return end0 + end1;
    }
};