// Link: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n^2) Sc: O(n)
//Approach: Dynamic Programming
// We can use dynamic programming to find the maximum height of the stack of cuboids. We can sort the cuboids by their dimensions and then use a dp array to store the maximum height of the stack ending with each cuboid. We can then iterate through the cuboids and for each cuboid, we can check if it can be placed on top of any of the previous cuboids and update the dp array accordingly. Finally, we can return the maximum value in the dp array as the answer.
class Solution
{
public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++)
            {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
