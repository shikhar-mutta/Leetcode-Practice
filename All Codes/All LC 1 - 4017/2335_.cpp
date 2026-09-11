// Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Simulation. TC: O(n * log n), SC: O(1)
    int fillCups(vector<int> &amount)
    {
        int ans = 0;
        // We can fill 2 cups in 1 second,
        // so we will always try to fill the 2 most filled cups first.
        while (amount[0] > 0 || amount[1] > 0 || amount[2] > 0)
        { // Sort the amount of water in the cups in non-decreasing order.
            sort(amount.begin(), amount.end());
            if (amount[1] > 0)
            {
                amount[1]--;
            }
            if (amount[2] > 0)
            {
                amount[2]--;
            }
            ans++;
        }
        return ans;
    }
};
