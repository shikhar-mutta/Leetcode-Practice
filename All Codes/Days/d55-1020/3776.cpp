// Link: https://leetcode.com/problems/minimum-moves-to-balance-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    // Approach:
    //  1. Calculate the sum of the balance array and find the index of the last negative element.
    //  2. If the sum is negative, return -1 as it's impossible to balance
    //  3. If there are no negative elements, return 0 as the array is already balanced.
    //  4. Calculate the total amount needed to balance the last negative element.
    //  5. Iterate through the array in both directions from the last negative element, taking
    //     positive elements to balance the negative element, and calculate the total moves required.
    long long minMoves(vector<int> &balance)
    {
        int n = balance.size();

        long long sum = 0;
        int neg = -1;

        for (int i = 0; i < n; i++)
        {
            sum += balance[i];
            if (balance[i] < 0)
                neg = i;
        }

        if (sum < 0)
            return -1;

        if (neg == -1)
            return 0;

        long long need = -balance[neg];
        long long ans = 0;

        for (int d = 1; d < n && need > 0; d++)
        {

            int left = (neg - d + n) % n;

            if (balance[left] > 0)
            {
                long long take = min(need, (long long)balance[left]);
                need -= take;
                ans += take * d;
            }

            int right = (neg + d) % n;

            if (left != right && balance[right] > 0 && need > 0)
            {
                long long take = min(need, (long long)balance[right]);
                need -= take;
                ans += take * d;
            }
        }

        if (need > 0)
            return -1;

        return ans;
    }
};