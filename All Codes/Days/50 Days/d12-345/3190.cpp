// Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    int minimumOperations(vector<int> &nums)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] % 3 != 0)
                count += min(3 - nums[i] % 3, nums[i] % 3);
        return count;
    }
};
