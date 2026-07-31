// Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach: The problem can be solved by iterating through the corridor string and counting the number of plants. We can then calculate the number of ways to divide the corridor based on the number of plants and the distance between them. If the number of plants is odd or zero, we return 0. Otherwise, we return the product of the distances between the plants modulo 1e9 + 7.
#define ll long long
class Solution
{
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor)
    {

        ll count = 0;
        ll n = corridor.size();
        ll lastIdx = -1;

        ll ans = 1; // We need to multiply later so 1

        for (ll i = 0; i < n; i++)
        {
            if (corridor[i] == 'P')
            {
                continue;
            }

            count++;

            if (count % 2 == 1 && count > 2)
            {
                ll bars = i - lastIdx;
                ans = (ans * bars) % mod;
            }

            lastIdx = i;
        }

        return (count == 0 || count % 2 == 1 ? 0 : ans);
    }
};