// Link: https://leetcode.com/problems/patching-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + log(n)) where n is the size of the input array nums.
    // SC: O(1) as we are using only a few variables to keep track of the current reach and the number of patches needed.
    // Approach:
    //  1. We can use a greedy approach to solve this problem. We start with a variable reach initialized to 0, which represents the maximum number that can be formed using the current elements in the array. We also keep track of the current index i in the input array nums and the number of patches needed. We iterate through the input array nums and for each element, we check if it is less than or equal to reach + 1. If it is, we can use this element to extend our reach and we update reach accordingly. If it is greater than reach + 1, we need to add a patch to the array. We add reach + 1 to the array and update reach accordingly. We continue this process until reach is greater than or equal to n. Finally, we return the number of patches needed.
    int minPatches(vector<int> &nums, int n)
    {
        long long reach = 0;
        int i = 0, patches = 0;
        int sz = nums.size();
        while (reach < n)
        {
            if (i < sz && nums[i] <= reach + 1)
            {
                reach += nums[i];
                i++;
            }
            else
            {
                reach += reach + 1;
                patches++;
            }
        }
        return patches;
    }
};
