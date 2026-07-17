// Link: https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(1)
    // Approach:
    // 1. Calculate the cost of making the two arrays identical without using k.
    // 2. If the cost is less than or equal to k, return the cost.
    // 3. If the cost is greater than k, sort both arrays and calculate the cost
    //    of making the two arrays identical using k.
    // 4. Return the minimum of the two costs.
    long long minCost(vector<int> &arr, vector<int> &brr, long long k)
    {
        long long cost = k;
        long long cost1 = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            cost1 += abs(brr[i] - arr[i]);
        if (k >= cost1)
            return cost1;
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        for (int i = 0; i < n; ++i)
            cost += abs(brr[i] - arr[i]);
        return min(cost1, cost);
    }
};
