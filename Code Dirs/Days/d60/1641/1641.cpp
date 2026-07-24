// Link: https://leetcode.com/problems/count-sorted-vowel-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input integer.
    // SC: O(1) for storing the result.
    // Approach:
    //        1. Use dynamic programming to count the number of sorted vowel strings of length n
    //        2. Initialize a vector dp of size 5 with all elements as 1
    //        3. Iterate through the lengths from 2 to n
    //        4. For each length, iterate through the vowels in reverse order and update the dp vector by adding the count of the next vowel to the current vowel
    //        5. Return the sum of all elements in the dp vector as the result.
    int countVowelStrings(int n)
    {
        vector<int> dp(5, 1);
        for (int len = 2; len <= n; ++len)
            for (int i = 3; i >= 0; --i)
                dp[i] += dp[i + 1];
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
