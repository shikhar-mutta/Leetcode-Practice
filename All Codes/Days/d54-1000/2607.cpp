// Link: https://leetcode.com/problems/make-k-subarray-sums-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // TC: O(nlogn).
    // SC: O(n).
    //   Approach:
    //   1. Iterate through the array and for each index i, find the cycle of elements that can be reached by repeatedly adding k to i and taking modulo n.
    //   2. Store the elements in the cycle in a vector and set them to 0 in the original array to avoid processing them again.
    //   3. Find the median of the cycle and calculate the total number of operations needed to make all elements in the cycle equal to the median.
    //   4. Return the total number of operations needed to make all elements in the array equal to the median of their respective cycles.
public:
    long long makeSubKSumEqual(vector<int> &arr, int k)
    {
        long long sz = arr.size(), res = 0;
        for (int i = 0; i < k; ++i)
        {
            vector<int> cycle;
            for (int j = i; arr[j] != 0; j = (j + k) % sz)
            {
                cycle.push_back(arr[j]);
                arr[j] = 0;
            }
            nth_element(begin(cycle), begin(cycle) + cycle.size() / 2, end(cycle));
            for (int n : cycle)
                res += abs(n - cycle[cycle.size() / 2]);
        }
        return res;
    }
};
