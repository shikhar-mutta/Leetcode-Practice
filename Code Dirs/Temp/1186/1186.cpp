// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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