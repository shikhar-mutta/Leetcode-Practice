// Link: https://leetcode.com/problems/circular-array-loop/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: Floyd's Cycle Detection Algorithm
// 1. We can use the Floyd's Cycle Detection Algorithm to detect cycles in the array.
// 2. We can use two pointers, slow and fast, to traverse the array. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
// 3. If there is a cycle, the slow and fast pointers will eventually meet at some point in the cycle.
// 4. We need to check if the cycle length is greater than 1, as a self-loop is not valid.

class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        auto next = [&](int i)
        {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                continue; // already visited / dead

            int slow = i, fast = i;
            // move only while direction stays the same as nums[i]
            while (nums[slow] * nums[next(slow)] > 0 &&
                   nums[fast] * nums[next(fast)] > 0 &&
                   nums[next(fast)] * nums[next(next(fast))] > 0)
            {

                slow = next(slow);
                fast = next(next(fast));

                if (slow == fast)
                {
                    if (slow != next(slow))
                        return true; // cycle length > 1
                    break;           // self-loop, invalid
                }
            }

            // mark the whole traversed path as dead (0)
            int j = i, dir = nums[i];
            while (nums[j] * dir > 0)
            {
                int nxt = next(j);
                nums[j] = 0;
                j = nxt;
            }
        }
        return false;
    }
};