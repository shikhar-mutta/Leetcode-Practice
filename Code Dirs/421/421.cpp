// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n). SC: O(n).
// Approach: We can use a recursive approach to find the maximum XOR of two numbers in an array. The idea is to sort the numbers based on their bits and then recursively find the maximum XOR by comparing the bits of the numbers. We can use a stack to keep track of the ranges of numbers that we need to compare.
class Solution
{
public:
    int sort_range(vector<int> &nums, pair<int, int> range, int bitMask)
    {
        int l = range.first;
        int r = range.second;
        while (l < r)
        {
            if ((nums[l] & bitMask) != 0)
            {
                std::swap(nums[l], nums[r--]);
            }
            else
            {
                l++;
            }
        }
        if ((nums[l] & bitMask) == 0)
        {
            return l;
        }
        else
        {
            return l - 1;
        }
    }

    int findMaximumXOR(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int diff = *min_it ^ *max_it;
        if (diff == 0)
            return 0;

        int leading_zeros = __builtin_clz(diff);
        unsigned int startBitMask = 1U << (31 - leading_zeros);

        auto root_range = make_pair(0, (int)nums.size() - 1);
        int m = sort_range(nums, root_range, startBitMask);

        struct Task
        {
            pair<int, int> r0;
            pair<int, int> r1;
            unsigned int mask;
        };

        vector<Task> stack;
        stack.reserve(32);

        stack.push_back({make_pair(root_range.first, m), make_pair(m + 1, root_range.second), startBitMask >> 1});

        unsigned int global_maxX = 0;

        while (!stack.empty())
        {
            Task current = stack.back();
            stack.pop_back();

            pair<int, int> range0 = current.r0;
            pair<int, int> range1 = current.r1;
            unsigned int bitMask = current.mask;

            if (range0.first > range0.second || range1.first > range1.second)
            {
                continue;
            }

            if (bitMask == 0)
            {
                unsigned int curX = nums[range0.first] ^ nums[range1.first];
                if (curX > global_maxX)
                    global_maxX = curX;
                continue;
            }

            if ((global_maxX != 0) && ((nums[range0.first] ^ nums[range1.first]) | (bitMask * 2 - 1)) <= global_maxX)
            {
                continue;
            }

            int m0 = sort_range(nums, range0, bitMask);
            int m1 = sort_range(nums, range1, bitMask);

            bool has_zero0 = (m0 >= range0.first);
            bool has_one0 = (m0 < range0.second);
            bool has_zero1 = (m1 >= range1.first);
            bool has_one1 = (m1 < range1.second);

            unsigned int newBitMask = bitMask >> 1;

            bool path1 = has_zero0 && has_one1;
            bool path2 = has_one0 && has_zero1;

            if (path1 || path2)
            {
                if (path1)
                {
                    stack.push_back({make_pair(range0.first, m0), make_pair(m1 + 1, range1.second), newBitMask});
                }
                if (path2)
                {
                    stack.push_back({make_pair(m0 + 1, range0.second), make_pair(range1.first, m1), newBitMask});
                }
            }
            else
            {
                stack.push_back({range0, range1, newBitMask});
            }
        }

        return global_maxX;
    }
};