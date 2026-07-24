// Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //   1. Initialize a variable ans to store the total number of substrings and a variable len to keep track of the length of consecutive '1's.
    //   2. Iterate through the string s character by character.
    //   3. If the current character is '1', increment len by 1 and add len to ans. This accounts for all substrings ending at the current position that consist of only '1's.
    //   4. If the current character is '0', reset len to 0 since it breaks the sequence of '1's.
    //   5. After processing all characters, return ans modulo 10^9 + 7 to handle large numbers.
    int numSub(string s)
    {
        long long mod = 1e9 + 7;
        int n = s.size();
        int i = 0;
        long long ans = 0;
        while (i < n)
        {
            int len = 0;
            char ch = s[i];
            while (i < n && s[i] == ch)
            {
                len++;
                i++;
            }
            if (ch == '0')
                continue;
            ans = ans + ((1LL * len * (len + 1)) / 2) % mod;
        }

        return ans % mod;
    }
};