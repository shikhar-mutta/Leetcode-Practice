// Link: https://leetcode.com/problems/magnetic-force-between-two-balls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)
// SC: O(1)
// Approach:
//  1. Sort the 'position' array.
//  2. Use binary search to find the maximum minimum distance between any two balls.
class Solution
{
public:
    bool canPlaceBalls(int x, vector<int> &position, int m)
    {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i)
        {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x)
            {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(mid, position, m))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return answer;
    }
};