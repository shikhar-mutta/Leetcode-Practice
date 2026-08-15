// Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the length of the array
// SC: O(1) as we are using a constant space
// Approach:
//  1. We can sort the array and use two pointers to find the pairs that sum to k.
//  2. We can then return the count of such pairs.
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        ios ::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int j = n - 1;
        sort(nums.begin(), nums.end());
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == k)
            {
                cnt++;
                i++;
                j--;
            }
            else if (sum < k)
            {
                i++;
            }
            else if (sum > k)
            {
                j--;
            }
        }
        return cnt;
    }
};
