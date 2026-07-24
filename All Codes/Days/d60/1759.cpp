// Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: 
    //TC: O(n), SC: O(1)
    // Approach: 
    //   1. We can iterate through the string and count the number of consecutive characters.
    //   2. For each group of consecutive characters, we can calculate the number of homogenous substrings using the formula n*(n+1)/2, where n is the number of consecutive characters.
    //   3. We can keep a running total of the number of homogenous substrings and return the total at the end.
    // Note: We need to take the modulo of the result with 10^9 + 7 to avoid overflow.  
    int countHomogenous(string s)
    {
        const int MOD = 1000000007;
        long long ans = 0;
        long long count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                ans = (ans + count * (count + 1) / 2) % MOD;
                count = 1;
            }
        }
        ans = (ans + count * (count + 1) / 2) % MOD;
        return ans;
    }
};