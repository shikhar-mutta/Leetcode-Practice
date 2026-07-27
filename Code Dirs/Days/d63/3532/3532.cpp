// Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
// Approach: nums is sorted, so an edge between i and j (any i,j) exists
// in the transitive-closure sense iff every consecutive gap along the
// way is <= maxDiff. Assign a component id by scanning left to right,
// bumping the id whenever a consecutive gap exceeds maxDiff; two indices
// are connected iff they share a component id.
class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++)
            comp[i] = comp[i - 1] + (nums[i] - nums[i - 1] > maxDiff ? 1 : 0);

        vector<bool> ans;
        for (auto &q : queries)
            ans.push_back(comp[q[0]] == comp[q[1]]);
        return ans;
    }
};
