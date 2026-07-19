// Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of elements in the array.
// SC: O(1) as we are using constant space.
// Approach:
//  1. Iterate through the array in steps of 2.
//  2. For each pair of elements, calculate the score based on the smaller element
//  3. If the next element is smaller than the current element, add it to the score and continue to the next pair.
//  4. If the next element is larger than the current element, add the current element to the score and move to the next pair.
//  5. Return the total score after processing all elements in the array.
struct Solution
{
    static constexpr long long findScore(std::span<const int> nums) noexcept
    {
        long long total_score = 0;
        for (std::size_t i = 0; i < nums.size(); i += 2u)
        {
            long long score[2]{};
            int x = nums[i];
            for (int y; i + 1u != nums.size() && x > (y = nums[i + 1u]); ++i, x = y)
                score[i % 2u] += x;
            total_score += score[i % 2u] + x;
        }
        return total_score;
    }
};