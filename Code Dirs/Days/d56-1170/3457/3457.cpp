// Link: https://leetcode.com/problems/eat-pizzas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(NlogN), SC: O(1)
    //  Approach:
    //  1. Sort the pizzas in ascending order.
    //  2. Calculate the number of days (n/4) and split them into odd and even days.
    //  3. For odd days, take the largest pizzas (from the end of the sorted array).
    //  4. For even days, skip one pizza and take the next largest pizza.
    //  5. Sum the weights of the selected pizzas to get the maximum weight.
    //  Note: The input array is guaranteed to have a length that is a multiple of 4, so we can safely divide by 4 to get the number of days.
    long long maxWeight(vector<int> &pizzas)
    {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int days = n / 4;
        int ed = days / 2;
        int od = (days + 1) / 2;
        long long ans = 0;
        int r = n - 1;
        for (int i = 0; i < od; i++)
        {
            ans += pizzas[r];
            r--;
        }
        for (int i = 0; i < ed; i++)
        {
            r--;
            ans += pizzas[r];
            r--;
        }
        return ans;
    }
};