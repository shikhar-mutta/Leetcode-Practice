// Link: https://leetcode.com/problems/smallest-rotation-with-highest-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: for rotation k, element at index i moves to (i-k+n)%n and
//  scores a point iff nums[i] <= new position j. As k varies, j=(i-k)%n
//  sweeps every value once, so the valid j's [nums[i], n-1] map to a
//  contiguous range of k's: [(i+1)%n, (i-nums[i]+n)%n]. Mark that range
//  with a difference array, then prefix-sum to find the best k.
class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int n = nums.size();

        // Initialize variables to track the maximum score and best rotation
        int maxScore = -1;
        int bestK = n;

        // Difference array to track score changes at each rotation k
        vector<int> scoreDelta(n);

        // For each element, calculate the range of k values where it
        // contributes to the score
        for (int i = 0; i < n; ++i)
        {
            // Calculate the left boundary: rotation where nums[i] starts
            // contributing When k = i+1, element at index i moves to position
            // n-1
            int leftBoundary = (i + 1) % n;

            // Calculate the right boundary: last rotation where nums[i] still
            // contributes Element contributes when new_index >= nums[i]
            // new_index = (i - k + n) % n >= nums[i]
            // Solving for k: k <= (i + 1 - nums[i] + n) % n
            int rightBoundary = (n + i + 1 - nums[i]) % n;

            // Mark the range [leftBoundary, rightBoundary) using difference
            // array
            ++scoreDelta[leftBoundary];
            --scoreDelta[rightBoundary];
        }

        // Calculate cumulative scores and find the rotation with maximum score
        int currentScore = 0;
        for (int k = 0; k < n; ++k)
        {
            currentScore += scoreDelta[k];

            // Update best rotation if current score is higher
            if (currentScore > maxScore)
            {
                maxScore = currentScore;
                bestK = k;
            }
        }

        return bestK;
    }
};