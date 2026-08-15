// Link: https://leetcode.com/problems/minimum-cost-to-move-between-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
//  Approach: since nums is sorted, moving forward (l<r) only ever requires moving to the right, and moving backward (l>r) only ever requires moving to the left. Precompute the closest index for each index, and then precompute prefix sums of costs for moving right and left. For each query, calculate the cost of moving directly and the cost of walking through the closest indices, and return the minimum of the two.
class Solution
{
public:
    vector<int> minCost(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        vector<int> closest(n);
        for (int x = 0; x < n; x++)
        {
            if (x == 0)
                closest[x] = 1;
            else if (x == n - 1)
                closest[x] = n - 2;
            else
            {
                long long dl = (long long)nums[x] - nums[x - 1]; // left gap
                long long dr = (long long)nums[x + 1] - nums[x]; // right gap
                closest[x] =
                    (dl <= dr) ? (x - 1) : (x + 1); // tie -> smaller index
            }
        }

        vector<long long> prefRight(n, 0), prefLeft(n, 0);
        for (int i = 0; i + 1 < n; i++)
        {
            long long gap = (long long)nums[i + 1] - nums[i];
            long long rc = (closest[i] == i + 1) ? 1 : gap; // i -> i+1
            long long lc = (closest[i + 1] == i) ? 1 : gap; // i+1 -> i
            prefRight[i + 1] = prefRight[i] + rc;
            prefLeft[i + 1] = prefLeft[i] + lc;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            if (l == r)
            {
                ans.push_back(0);
                continue;
            }

            long long direct = llabs((long long)nums[l] - nums[r]); // one jump
            long long walk;
            if (l < r)
                walk = prefRight[r] - prefRight[l]; // step right l..r-1
            else
                walk = prefLeft[l] - prefLeft[r]; // step left  r..l-1

            ans.push_back((int)min(direct, walk));
        }
        return ans;
    }
};