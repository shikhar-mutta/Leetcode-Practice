// Link: https://leetcode.com/problems/h-index-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) - Binary Search
    // SC: O(1)
    //  Approach:
    //  1. Use binary search to find the first index where citations[index] >= n - index
    //  2. Return n - index as the h-index
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (citations[mid] >= n - mid)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return n - lo;
    }
};
