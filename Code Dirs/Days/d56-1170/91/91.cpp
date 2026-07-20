// Link: https://leetcode.com/problems/decode-ways/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) - We iterate through the string once, where n is the length of the input string s. For each character, we perform constant time operations to update the dp array.
    // SC: O(n) - We use a dp array of size n+1 to store the number of ways to decode the string up to each index. Therefore, the space complexity is O(n).
    // Approach:
    //    1. We initialize a dp array of size n+1, where n is the length of the input string s. dp[i] represents the number of ways to decode the substring s[0..i-1].
    //    2. We set dp[0] = 1, as there is one way to decode an empty string. We set dp[1] = 1 if the first character is not '0', as there is one way to decode a single character.
    //    3. We iterate through the string from index 2 to n. For each character, we check if it can be decoded as a single digit (if it is not '0') and update dp[i] accordingly. We also check if the last two characters can be decoded as a two-digit number (if it is between 10 and 26) and update dp[i] accordingly.
    //    4. Finally, we return dp[n], which represents the total number of ways to decode the entire string.
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
