// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. Use two variables keep and del to keep track of the maximum subarray sum ending at the current index with and without deletion respectively.
    //  2. Iterate through the array and update keep and del based on the current element.
    //  3. Update the result with the maximum of keep and del at each step.
    //  4. Return the result after iterating through the entire array.
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        int keep = arr[0];
        int del = 0;
        int res = arr[0];
        for (int i = 1; i < n; i++)
        {
            del = max(del + arr[i], keep);
            keep = max(keep + arr[i], arr[i]);
            res = max({res, keep, del});
        }
        return res;
    }
};