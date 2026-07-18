// Link: https://leetcode.com/problems/sort-array-by-parity-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int j = 1, n = nums.size();
        // We will iterate over the even indexed elements and check if they are odd. If they are odd, we will find the next odd indexed element which is even and swap them.
        for (int i = 0; i < n; i += 2)
        {
            // If the element at the even index is odd, we need to find an even element at an odd index to swap with.
            if (nums[i] % 2 != 0)
            {
                while (nums[j] % 2 != 0)
                    j += 2;
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
