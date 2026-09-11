// Link: https://leetcode.com/problems/kth-missing-positive-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Binary search for the first index i such that arr[i] - (i + 1) >= k
        int lo = 0, hi = arr.size();
        // arr[i] - (i + 1) gives the number of missing numbers until index i
        while (lo < hi)
        {
            int mid = (lo + hi) / 2; // number of missing numbers until mid is arr[mid] - (mid + 1)
            if (arr[mid] - (mid + 1) >= k)
                hi = mid; // arr[mid] - (mid + 1) >= k means the kth missing number is at ===> mid or before mid
            else
                lo = mid + 1; // If the number of missing numbers until mid is less than k, then the kth missing number is at ===>  after mid
        }

        return lo + k;
    }
};
