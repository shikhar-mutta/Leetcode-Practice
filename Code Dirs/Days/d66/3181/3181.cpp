// Link: https://leetcode.com/problems/maximum-total-reward-using-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k)  SC: O(n * k)
// Approach: dp[i][j] = maximum length of good subsequence starting at index i with j deletions left. For each index, we can either delete it (if we have deletions left) or take it (if it's not a duplicate of the next element). Use a map to track the next occurrence of each number.  
class Solution
{
public:
    int maxTotalReward(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        unordered_set<int> set(nums.begin(), nums.end());
        unordered_map<int, int> cache;
        return nums.back() + helper(nums.back() - 1, nums, set, cache);
    }

private:
    int helper(int num, const vector<int> &nums, const unordered_set<int> &set,
               unordered_map<int, int> &cache)
    {
        if (cache.find(num) != cache.end())
        {
            return cache[num];
        }
        if (set.find(num) != set.end() || num == 0)
        {
            return num;
        }

        int ind = bisectLeft(nums, num);
        int res = 0;

        for (int i = 0; i < ind; ++i)
        {
            res = max(res, nums[i] + helper(min(nums[i] - 1, num - nums[i]),
                                            nums, set, cache));
        }

        cache[num] = res;
        return res;
    }

    int bisectLeft(const vector<int> &arr, int target)
    {
        int lo = 0;
        int hi = arr.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};