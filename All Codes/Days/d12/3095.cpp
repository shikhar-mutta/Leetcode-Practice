// Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(1)
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            { // Perform bitwise OR operation with the current element
                sum |= nums[j];
                if (sum >= k)
                { // Update the minimum length of the subarray
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};