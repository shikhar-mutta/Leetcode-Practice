// Link: https://leetcode.com/problems/jump-game-v/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*d) where n is the number of elements in arr and d is the maximum jump distance
// SC: O(n) where n is the number of elements in arr and d is the maximum jump distance
// Approach: DFS + Memoization
// We can use DFS to explore all possible jumps from each index. We can use memoization to store the maximum number of indices we can visit starting from each index. The base case is when we reach an index that has already been visited, in which case we return the stored value. For each index, we can jump to the left and right within the distance d, and we can only jump to indices with a lower value than the current index. We keep track of the maximum number of indices we can visit starting from each index and return the maximum value among all indices.
class Solution
{
vector<int> memo;
int dfs(vector<int> &arr, int i, int d)
{
    if (memo[i] != -1)
        return memo[i];
    int best = 1;
    int n = arr.size();
    for (int dir = -1; dir <= 1; dir += 2)
    {
        for (int step = 1; step <= d; step++)
        {
            int j = i + dir * step;
            if (j < 0 || j >= n || arr[j] >= arr[i])
                break;
            best = max(best, 1 + dfs(arr, j, d));
        }
    }
    memo[i] = best;
    return best;
}

public:
int maxJumps(vector<int> &arr, int d)
{
    int n = arr.size();
    memo.assign(n, -1);
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dfs(arr, i, d));
    return ans;
}
};
