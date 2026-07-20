// Link: https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(1)
    // Approach:
    //  1. Sort the coins array
    //  2. Initialize reach to 0, added to 0, i to 0, n to size of coins array
    //  3. While reach is less than target, do the following:
    //     a. If i is less than n and coins[i] is less than or equal to reach + 1, add coins[i] to reach and increment i
    //     b. Else, add reach + 1 to reach and increment added
    //  4. Return added
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        long long reach = 0;
        int added = 0, i = 0, n = coins.size();
        while (reach < target)
        {
            if (i < n && coins[i] <= reach + 1)
                reach += coins[i++];
            else
            {
                reach += reach + 1;
                added++;
            }
        }
        return added;
    }
};
