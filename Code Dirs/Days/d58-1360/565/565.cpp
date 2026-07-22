// Link: https://leetcode.com/problems/array-nesting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    // Approach:
    //    1. We use a depth-first search (DFS) approach to explore the array and find the length of the longest set S. We maintain a visited array to keep track of the indices we have already visited. For each unvisited index, we start a DFS to explore the set S starting from that index. We count the number of unique indices we visit during the DFS and update the maximum length of S found so far. We repeat this process for all unvisited indices in the array. The time complexity is O(n) since we visit each index at most once, and the space complexity is O(n) due to the visited array.
    //    2. This approach is efficient and works well for the given problem constraints.
    //    3. The DFS function takes the current index, the visited array, the input array, and a reference to the count of unique indices visited. If the current index has already been visited, we return. Otherwise, we mark it as visited, increment the count, and recursively call DFS on the next index in the set S (which is nums[i]). This continues until we reach an index that has already been visited.
    void dfs(int i, vector<int> &vis, vector<int> &nums, int &cnt)
    {
        if (vis[i])
        {
            return;
        }
        vis[i] = 1;
        cnt++;

        dfs(nums[i], vis, nums, cnt);
    }
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vis(n, 0);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                dfs(i, vis, nums, cnt);
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};