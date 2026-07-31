// Link: https://leetcode.com/problems/count-special-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n)), SC: O(log(n))
//  Approach: We can count the number of special integers with fewer digits than n and then count the number of special integers with the same number of digits as n by iterating through the digits of n and keeping track of the digits used so far. For each digit, we can count the number of valid digits that can be used in the current position and multiply it by the number of valid combinations for the remaining positions. Finally, we can add the count of special integers with fewer digits and the count of special integers with the same number of digits to get the total count of special integers less than or equal to n.
class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        string s = to_string(n);
        int len = s.size();
        int ans = 0;

        // numbers with fewer digits (1..len-1 digits), first digit 1-9, rest distinct from remaining 9
        for (int L = 1; L < len; L++)
        {
            int cnt = 9;
            int avail = 9;
            for (int i = 1; i < L; i++)
            {
                cnt *= avail;
                avail--;
            }
            ans += cnt;
        }

        // same length as n, tight prefix
        vector<int> used(10, 0);
        for (int i = 0; i < len; i++)
        {
            int d = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int v = start; v < d; v++)
            {
                if (used[v])
                    continue;
                int avail = 10 - (i + 1);
                int cnt = 1;
                int remainingPositions = len - i - 1;
                for (int k = 0; k < remainingPositions; k++)
                    cnt *= (avail - k);
                ans += cnt;
            }
            if (used[d])
                break;
            used[d] = 1;
            if (i == len - 1)
                ans += 1; // n itself is special
        }

        return ans;
    }
};
