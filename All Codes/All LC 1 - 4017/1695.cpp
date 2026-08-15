// Link: https://leetcode.com/problems/maximum-erasure-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array.
    // SC: O(1) for storing the seen array of fixed size 10001
    // Approach:
    //     1. Use a sliding window approach with two pointers, left and right.
    //     2. Use a boolean array seen to keep track of the elements in the current window.
    //     3. Iterate through the nums array with the right pointer.
    //     4. If the current element nums[right] has been seen before, move the left pointer to the right until nums[right] is unique in the current window, updating the current score and seen array accordingly.
    //     5. Add the current element nums[right] to the current score and mark it as seen.
    //     6. Update the maximum score if the current score is greater than the maximum score.
    //     7. Return the maximum score after iterating through the entire array.
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int max_score = 0, current_score = 0, left = 0;
        bool seen[10001] = {false};
        for (int right = 0; right < nums.size(); ++right)
        {
            while (seen[nums[right]])
            {
                current_score -= nums[left];
                seen[nums[left]] = false;
                left++;
            }
            seen[nums[right]] = true;
            current_score += nums[right];
            max_score = std::max(max_score, current_score);
        }
        return max_score;
    }
};
