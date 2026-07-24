// Link: https://leetcode.com/problems/stone-game-vii/description/

#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the length of the input array.
    // SC: O(n) for storing the dp array.
    // Approach:
    //     1. Use dynamic programming to calculate the maximum score difference between Alice and Bob.
    //     2. Create a dp array to store the maximum score difference for each subarray of stones.
    //     3. Iterate through the stones array in reverse order, calculating the maximum score difference for each subarray.
    //     4. For each subarray, calculate the current sum of stones and the maximum score difference for removing the leftmost or rightmost stone and update the dp array accordingly.
    //     5. Return the maximum score difference for the entire array, which is stored in dp[n - 1].
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> dp(n, 0);
        for (int i = n - 2; i >= 0; --i)
        {
            int csum = stones[i];
            for (int j = i + 1; j < n; ++j)
            {
                csum += stones[j];
                int rml = csum - stones[i] - dp[j];
                int rmr = csum - stones[j] - dp[j - 1];
                dp[j] = max(rml, rmr);
            }
        }

        return dp[n - 1];
    }
};