// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n), SC: O(n)
//  Approach: For each of the k subsequences, we can find the length of the longest non-decreasing subsequence (LNDS) using a modified version of the patience sorting algorithm. The minimum number of operations required to make the subsequence non-decreasing is equal to the length of the subsequence minus the length of the LNDS. We can then sum up the minimum number of operations required for all k subsequences to get the final answer.
class Solution
{
public:
    int kIncreasing(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> tails;
        tails.reserve(n);
        int ans = 0;

        for (int ind = 0; ind < k; ind++)
        {
            tails.push_back(nums[ind]);

            int sz = 1;

            for (int i = ind + k; i < n; i += k)
            {
                auto it = upper_bound(tails.begin(), tails.end(), nums[i]);
                if (it == tails.end())
                {
                    tails.push_back(nums[i]);
                }
                else
                {
                    *it = nums[i];
                }
                sz++;
            }
            ans += (sz - tails.size());
            tails.clear();
        }
        return ans;
    }
};