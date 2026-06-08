// Link: https://leetcode.com/problems/trionic-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isTrionic(vector<int> &nums)
    {

        int n = nums.size(), i = 0, cnt = 3, dir = 1;
        if (n < 3)
            return false;

        while (i < n - 1 && cnt > 0)
        {
            int prev = i; // store the current index before moving
            if (dir == 1)
                while (i < n - 1 && nums[i] < nums[i + 1])
                    i++;
            else
                while (i < n - 1 && nums[i] > nums[i + 1])
                    i++;
            if (i == prev) // no change in direction, not a valid trionic array
                return false;
            dir = -dir; // change direction
            cnt--;      // decrease the count of direction changes
        }
        return i == n - 1 && cnt == 0;
    };
};