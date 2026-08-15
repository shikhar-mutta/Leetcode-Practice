// Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: for each index, the required change nums1[i] -> nums2[i]
// must be a multiple of k (each operation shifts one +k/-k pair), so any
// non-multiple difference makes it impossible. Sum up all positive
// differences (need decreasing) and negative differences (need
// increasing) separately; since every operation both increases one
// element and decreases another by k, these two totals must match, and
// the answer is that shared total divided by k.
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long posSum = 0, negSum = 0; // total amount to decrease / increase
        int n = nums1.size();

        for (int i = 0; i < n; ++i) {
            long long diff = nums1[i] - nums2[i];
            if (k == 0) {
                if (diff != 0)
                    return -1; // no operation possible; must already match
                continue;
            }
            if (diff % k != 0)
                return -1; // can't adjust by a non-multiple of k
            if (diff > 0)
                posSum += diff;
            else
                negSum += -diff;
        }

        if (k == 0)
            return 0; // all differences were zero
        if (posSum != negSum)
            return -1; // increases and decreases must balance
        return posSum / k;
    }
};
