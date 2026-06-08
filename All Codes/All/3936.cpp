// Link: https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minimumSwaps(vector<int> &nums)
    {
        int n = nums.size(), zI = 0, nZI = n - 1, swaps = 0;
        while (zI < nZI)
        {
            while (zI < n && nums[zI] != 0)
                zI++;
            while (nZI >= 0 && nums[nZI] == 0)
                nZI--;

            if (zI >= nZI)
                break;

            swap(nums[zI], nums[nZI]);
            swaps++;
            zI++;
            nZI--;
        }
        return swaps;
    }
};
