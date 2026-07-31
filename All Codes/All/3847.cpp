// Link: https://leetcode.com/problems/find-the-score-difference-in-a-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: simulate directly — track which player is active, applying
// a swap before scoring whenever nums[i] is odd or i is a (0-indexed)
// multiple-of-6 position (game index 5, 11, ...), then add the points to
// that player's total.
class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        int p1 = 0, p2 = 0;
        bool player1 = true, player2 = false;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                player1 = !player1;
                player2 = !player2;
            }
            if ((i + 1) % 6 == 0)
            {
                player1 = !player1;
                player2 = !player2;
            }
            if (player1)
                p1 += nums[i];
            if (player2)
                p2 += nums[i];
        }
        return p1 - p2;
    }
};