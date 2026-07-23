// Link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of elements in the input array nums.
    // SC: O(1), since we are using a constant amount of extra space to store the leftMax, overallMax, and partitionIdx variables.
    // Approach:
    //   1. We initialize leftMax and overallMax to the first element of the input array nums, and partitionIdx to 0.
    //   2. We iterate through the input array nums starting from the second element.
    //   3. For each element, we update overallMax to be the maximum of overallMax and the current element.
    //   4. If the current element is less than leftMax, we update leftMax to be overallMax and set partitionIdx to the current index.
    //   5. After iterating through the entire array, we return partitionIdx + 1 as the length of the left partition.
    //   6. This approach ensures that all elements in the left partition are less than or equal to all elements in the right partition, and the left partition is as small as possible.
    int partitionDisjoint(vector<int> &nums)
    {
        int leftMax = nums[0], overallMax = nums[0];
        int partitionIdx = 0;
        for (int i = 1; i < (int)nums.size(); i++)
        {
            overallMax = max(overallMax, nums[i]);
            if (nums[i] < leftMax)
            {
                leftMax = overallMax;
                partitionIdx = i;
            }
        }
        return partitionIdx + 1;
    }
};
