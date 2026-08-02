// Link: https://leetcode.com/problems/find-the-minimum-cost-array-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)  SC: O(n * 2^n)
//  Approach: We can use a bitmask dynamic programming approach to solve this problem. We can use a bitmask to represent the elements that have been placed in the permutation. We can then use a recursive function to calculate the minimum score for each state of the bitmask. We can also use memoization to store the results of previously calculated states to avoid redundant calculations. Finally, we can reconstruct the lexicographically smallest permutation path by greedily choosing the next element that preserves the optimal cost.
class Solution
{
private:
    int n;
    int dp[1 << 14][14];

    int solve(int mask, int last, const vector<int> &nums)
    {
        // Base case: All elements have been placed
        if (mask == (1 << n) - 1)
        {
            // Complete the cycle back to perm[0], which we fixed as 0
            return abs(last - nums[0]);
        }

        if (dp[mask][last] != -1)
            return dp[mask][last];

        int minScore = 1e9;

        // Try placing any unvisited element next
        for (int nextVal = 0; nextVal < n; ++nextVal)
        {
            if (!(mask & (1 << nextVal)))
            {
                int cost = abs(last - nums[nextVal]) +
                           solve(mask | (1 << nextVal), nextVal, nums);
                minScore = min(minScore, cost);
            }
        }

        return dp[mask][last] = minScore;
    }

public:
    vector<int> findPermutation(vector<int> &nums)
    {
        n = nums.size();
        // Initialize DP table with -1
        for (int i = 0; i < (1 << n); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][j] = -1;
            }
        }

        // Calculate the optimal minimum score starting with 0 placed
        int targetOptimalScore = solve(1, 0, nums);

        // Reconstruct the lexicographically smallest permutation path
        vector<int> perm;
        perm.push_back(0);

        int currentMask = 1;
        int lastPlaced = 0;

        while (perm.size() < n)
        {
            // Greedily look for the smallest nextVal that preserves the optimal
            // cost
            for (int nextVal = 0; nextVal < n; ++nextVal)
            {
                if (!(currentMask & (1 << nextVal)))
                {
                    int costToTakeNext =
                        abs(lastPlaced - nums[nextVal]) +
                        solve(currentMask | (1 << nextVal), nextVal, nums);

                    if (costToTakeNext == dp[currentMask][lastPlaced])
                    {
                        perm.push_back(nextVal);
                        currentMask |= (1 << nextVal);
                        lastPlaced = nextVal;
                        break; // Break early to guarantee the lexicographically
                               // smallest path
                    }
                }
            }
        }

        return perm;
    }
};
