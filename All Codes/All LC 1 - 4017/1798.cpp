// Link: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of coins
    // SC: O(1)
    //  Approach:
    //  1. Sort the coins in ascending order
    //  2. Initialize a variable maxReach to 0, which will keep track of the maximum value that can be formed using the coins seen so far
    //  3. Iterate through the sorted coins and for each coin, check if it can be used to form a value greater than maxReach + 1. If it can, update maxReach to maxReach + coin value
    //  4. If a coin cannot be used to form a value greater than maxReach + 1, break the loop as no further coins can be used to form a value greater than maxReach + 1
    //  5. Return maxReach + 1 as the maximum number of consecutive values that can be formed using the coins
    int getMaximumConsecutive(vector<int> &coins)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= maxReach + 1)
            {
                maxReach += coins[i];
            }
            else
                break;
        }
        return maxReach + 1;
    }
};