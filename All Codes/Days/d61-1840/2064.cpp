// Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log m), SC: O(1)
//  Approach:
//  1. We can use binary search to find the minimum maximum value of products that can be distributed to any store.
//  2. We can set the lower bound of the binary search to 1 and the upper bound to the maximum value in the quantities array.
//  3. We can then check if it is possible to distribute the products to the stores such that the maximum value of products distributed to any store is less than or equal to the mid value of the binary search.
//  4. If it is possible, we can update the upper bound of the binary search to mid, otherwise we can update the lower bound of the binary search to mid + 1.
//  5. We can repeat this process until the lower bound is equal to the upper bound, at which point we can return the lower bound as the minimum maximum value of products that can be distributed to any store.
class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            long long stores = 0;
            for (int q : quantities)
                stores += (q + mid - 1) / mid; // ceil(q / mid)
            if (stores <= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};