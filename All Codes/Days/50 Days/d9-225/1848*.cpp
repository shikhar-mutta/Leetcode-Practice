// Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        for (int i = 0;; i++)
        {
            if (start - i >= 0 && nums[start - i] == target) // check left side
                return i;
            if (start + i < nums.size() && nums[start + i] == target) // check right side
                return i;
        }
    }
};
