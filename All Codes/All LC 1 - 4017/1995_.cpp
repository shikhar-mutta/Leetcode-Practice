// Link: https://leetcode.com/problems/count-special-quadruplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int countQuadruplets(vector<int> &nums)
    // {
    //     int n = nums.size(), cnt = 0;

    //     for (int i = 0; i < n - 3; i++)
    //         for (int j = i + 1; j < n - 2; j++)
    //             for (int k = j + 1; k < n - 1; k++)
    //                 for (int l = k + 1; l < n; l++)
    //                     if (nums[i] + nums[j] + nums[k] - nums[l] == 0)
    //                         cnt++;

    //     return cnt;
    // }

    int countQuadruplets(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        unordered_map<int, int> pairSum;

        for (int c = 2; c < n - 1; c++)
        {
            // add all pairs (a, b) where b = c-1
            // IMP : nums[a] + nums[b] = nums[d] - nums[c]

            // add nums[a] + nums[b] to the map where b = c-1 and a < b
            for (int a = 0; a < c - 1; a++)
                pairSum[nums[a] + nums[c - 1]]++;

            // check if nums[d] - nums[c] is present in the map for all d > c
            for (int d = c + 1; d < n; d++)
                cnt += pairSum[nums[d] - nums[c]];
        }
        return cnt;
    }
};
