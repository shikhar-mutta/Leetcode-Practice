// Link: https://leetcode.com/problems/stone-game-viii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: Use dynamic programming to calculate the maximum score difference for the first player. We first compute the prefix sums of the array to represent the total score if the first player takes all stones up to a certain index. Then, we iterate backwards through the prefix sums, updating the maximum score difference based on whether the first player takes the current prefix sum or not. This allows us to find the optimal strategy for the first player in linear time and constant space.
auto x = []()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    int stoneGameVIII(vector<int> &A)
    {
        int N = A.size();
        for (int i = 1; i < N; ++i)
            A[i] += A[i - 1];
        int dp = A.back();
        for (int i = N - 2; i > 0; --i)
            dp = max(dp, A[i] - dp);
        return dp;
    }
};