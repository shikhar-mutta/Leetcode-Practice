// Link: https://leetcode.com/problems/max-consecutive-ones-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: sliding window allowing at most one zero; shrink from the left
// when a second zero enters
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, zeros = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
