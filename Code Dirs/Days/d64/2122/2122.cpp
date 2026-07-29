// Link: https://leetcode.com/problems/recover-the-original-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
//  Approach: The original array can be recovered by finding the difference between the maximum and minimum elements of the given array. The difference will be equal to the sum of the two elements that were added to the original array. We can then use a bitset to keep track of the elements that have been used to form pairs and check if the remaining elements can be paired up to form the original array.
class Solution
{
public:
    vector<int> recoverArray(vector<int> &nums)
    {
        const int n{static_cast<int>(nums.size() / 2)};
        sort(nums.begin(), nums.end());
        for (int d{1}; d <= n; ++d)
        {
            while (nums[d] == nums[d - 1])
                ++d;
            const int dif{nums[d] - nums[0]};
            if (dif % 2)
                continue;
            bool good{true};
            static bitset<2000> vis{};
            vis.reset();
            for (int i{0}, j{d}; i < 2 * n; ++i)
            {
                if (vis[i])
                    continue;
                while (j < 2 * n && (nums[j] - nums[i] < dif || vis[j]))
                    ++j;
                if (j >= 2 * n || nums[j] - nums[i] != dif)
                {
                    good = false;
                    break;
                }
                vis[j] = true;
            }
            if (good)
            {
                vector<int> res{};
                res.reserve(n);
                for (int i{0}; i < 2 * n; ++i)
                {
                    if (!vis[i])
                        res.push_back(nums[i] + dif / 2);
                }
                return res;
            }
        }
        unreachable();
    }
};