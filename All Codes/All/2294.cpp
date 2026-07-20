// Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // TC: O(n) where n is the size of nums.
    // SC: O(1) as we are using a static array of size 100001 to store the existence of elements in nums.
    //  Approach:
    //  1. We will create a static array of size 100001 to store the existence of elements in nums.
    //  2. We will iterate through the nums and mark the existence of each element in the static array.
    //  3. We will iterate through the static array and for each existing element, we will increment the count and skip the next k elements.
    //  4. We will return the count as the minimum number of subsequences required.
    //  5. Finally, we will reset the static array to false for the next test case.
    int partitionArray(vector<int> &nums, int k)
    {
        static const auto fast_io = []()
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            return nullptr;
        }();
        static bool exists[100001] = {false};
        int max_val = nums[0];
        for (const int x : nums)
        {
            exists[x] = true;
            max_val = std::max(max_val, x);
        }
        int count = 0;
        for (int i = 0; i <= max_val; ++i)
        {
            if (exists[i])
            {
                ++count;
                i += k;
            }
        }
        for (const int x : nums)
        {
            exists[x] = false;
        }
        return count;
    }
};