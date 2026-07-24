// Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*log(max(nums))), SC: O(1)
    // Approach: Binary Search
    //   1. We can use binary search to find the minimum possible maximum size of the bags.
    //   2. We can check if it is possible to split the balls into bags of size less than or equal to mid using the possible function.
    //   3. If it is possible, we can move the high pointer to mid - 1, otherwise we can move the low pointer to mid + 1.
    //   4. Finally, we can return the low pointer as the minimum possible maximum size of the bags.
    // Note: The possible function checks if it is possible to split the balls into bags of size less than or equal to mid by counting the number of operations needed to split the balls into bags of size less than or equal to mid. If the total number of operations needed is less than or equal to maxOperations, then it is possible to split the balls into bags of size less than or equal to mid.
    bool possible(vector<int> &nums, int maxOperations, int mid)
    {
        long long totalOps = 0;
        for (auto it : nums)
        {
            int ops = it / mid;
            if (it % mid == 0)
                ops -= 1;
            totalOps += ops;
        }
        return totalOps <= maxOperations;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(nums, maxOperations, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
