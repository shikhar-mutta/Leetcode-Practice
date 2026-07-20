// Link: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n)
    // SC: O(n)
    // Approach:
    //  1. Sort the power array.
    //  2. Use dynamic programming to calculate the maximum total damage.
    //  3. For each power[i], if it is equal to the previous power[i-1], then we can add it to the previous damage. Otherwise, we need to find the maximum damage we can get from the previous powers that are not adjacent to the current power[i].
    //  4. We can use a pointer j to keep track of the maximum damage we can get from the previous powers that are not adjacent to the current power[i].
    //  5. Finally, we return the maximum damage we can get from the last power.
    long long maximumTotalDamage(vector<int> &power)
    {
        sort(power.begin(), power.end());
        vector<long long> dp(power.size(), 0);
        dp[0] = power[0];
        int j = 0;
        long long maxDamage = 0;
        for (int i = 1; i < power.size(); i++)
        {
            if (power[i] == power[i - 1])
            {
                dp[i] = dp[i - 1] + power[i];
            }
            else
            {
                while (j < i && power[j] + 2 < power[i])
                {
                    maxDamage = max(maxDamage, dp[j]);
                    j++;
                }

                dp[i] = power[i] + maxDamage;
            }
        }
        while (j < power.size())
        {
            maxDamage = max(maxDamage, dp[j]);
            j++;
        }
        return maxDamage;
    }
};