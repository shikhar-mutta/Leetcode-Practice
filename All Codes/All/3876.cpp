// Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: nums1[i]-nums1[j] has parity = parity(nums1[i]) XOR
// parity(nums1[j]), so fixing a mismatched element always requires
// subtracting some ODD-valued smaller element. Target even (all
// nums2 even) forces every odd element to have a smaller odd helper —
// impossible for the globally smallest odd element, so it only works
// when there are no odd elements at all. Target odd works as long as
// every even element (if any) is larger than the smallest odd value.
class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        bool hasOdd = false, hasEven = false;
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int x : nums1)
        {
            if (x % 2 == 0)
            {
                hasEven = true;
                minEven = min(minEven, x);
            }
            else
            {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }
        bool targetEvenOk = !hasOdd;
        bool targetOddOk = !hasEven || (hasOdd && minOdd < minEven);
        return targetEvenOk || targetOddOk;
    }
};
