// Link: https://leetcode.com/problems/circular-array-loop/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: for each starting index, use slow/fast pointers moving in the
// fixed direction from that start; a cycle of length > 1 with consistent
// direction is a valid loop. Mark visited indices with 0 to skip re-scanning.
class Solution {
    int n;

    int next(vector<int>& nums, int i) {
        return ((i + nums[i]) % n + n) % n;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = i;
            bool forward = nums[i] > 0;
            while (true) {
                slow = next(nums, slow);
                if (nums[slow] == 0 || (nums[slow] > 0) != forward) break;
                fast = next(nums, fast);
                if (nums[fast] == 0 || (nums[fast] > 0) != forward) break;
                fast = next(nums, fast);
                if (nums[fast] == 0 || (nums[fast] > 0) != forward) break;
                if (slow == fast) {
                    if (slow == next(nums, slow)) break; // single-element cycle
                    return true;
                }
            }
            // mark this chain as visited (dead end)
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == forward) {
                int nj = next(nums, j);
                nums[j] = 0;
                j = nj;
            }
        }
        return false;
    }
};
