// Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: DP tracking, at each index, the min swaps needed if index i
// is NOT swapped (keep) vs IS swapped. Transition checks which of the
// two "both strictly increasing" conditions hold between consecutive
// indices (no-swap-compatible and/or swap-compatible) to combine with
// the previous state's keep/swap costs.
class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int keep = 0, swap_ = 1;
        for (int i = 1; i < n; i++)
        {
            int nkeep = INT_MAX, nswap = INT_MAX;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                nkeep = min(nkeep, keep);
                nswap = min(nswap, swap_ + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
            {
                nkeep = min(nkeep, swap_);
                nswap = min(nswap, keep + 1);
            }
            keep = nkeep;
            swap_ = nswap;
        }
        return min(keep, swap_);
    }
};
