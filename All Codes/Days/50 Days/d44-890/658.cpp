// Link: https://leetcode.com/problems/find-k-closest-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n-k) + k) SC: O(k)
    // Approach: Binary search the left edge of the k-wide window. The right edge is determined by the left edge.
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // Binary search the left edge of the k-wide window.
        int lo = 0, hi = arr.size() - k;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            // If x is closer to arr[mid+k] (or on a tie with arr[mid],
            // the tie-break prefers the smaller element => keep left), shift right.
            if (x - arr[mid] > arr[mid + k] - x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
