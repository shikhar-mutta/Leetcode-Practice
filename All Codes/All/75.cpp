// Link: https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // approach1: doutch national flag algorithm
        // [0, low)   → all 0s
        // [low, mid) → all 1s   ← low is the start of this region
        // [mid, high]→ unsorted
        // (high, n-1]→ all 2s

        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
