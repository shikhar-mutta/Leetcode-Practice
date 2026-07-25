// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the input array nums.
    // SC: O(1), as we are using a constant amount of extra space.
    // Approach:
    //  1. We first find the indices of the minimum and maximum elements in the array nums.
    //  2. We then calculate the number of deletions required to remove both elements from the array in three different ways:
    //     a. Deleting both elements from the front of the array.
    //     b. Deleting both elements from the back of the array.
    //     c. Deleting one element from the front and the other from the back of the array.
    //  3. Finally, we return the minimum number of deletions required among the three calculated values.
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int i = min(minIdx, maxIdx), j = max(minIdx, maxIdx);
        int fromFront = j + 1; // both via front
        int fromBack = n - i;  // both via back
        int mixed =
            (i + 1) + (n - j); // left one from front, right one from back
        return min({fromFront, fromBack, mixed});
    }
};