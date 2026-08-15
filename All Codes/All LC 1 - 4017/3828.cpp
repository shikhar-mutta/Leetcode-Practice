// Link: https://leetcode.com/problems/final-element-after-subarray-deletions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: on her very first move Alice can remove any subarray of size
// n-1 (legal since n-1<n), which lets her immediately end the game by
// keeping just the better of the two endpoints. Verified via brute-force
// minimax over small cases that no other line of play ever beats this
// for her, so the answer is simply max(nums[0], nums[n-1]).
class Solution
{
public:
    int finalElement(vector<int> &nums)
    {
        return max(nums.front(), nums.back());
    }
};
