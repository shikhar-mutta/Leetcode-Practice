// Link: https://leetcode.com/problems/minimum-absolute-difference-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m * 100 * log(n)) where n is the length of the nums and m is the number of queries
// SC: O(n) where n is the length of the nums
// Approach: Binary Search + Prefix Sum
//   1. Create a vector of vectors to store the indices of each number in the nums array.
//   2. For each query, use binary search to find the indices of the numbers in the range [l, r].
//   3. Calculate the minimum absolute difference between the numbers in the range [l, r] and store it in the answer vector.
//  4. Return the answer vector.
class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<vector<int>> indices(101);
        int i = 0;
        for (int x : nums)
        {
            indices[x].push_back(i++);
        }
        vector<int> ans(queries.size());
        int j = 0;
        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            int prev = -1;

            int d = INT_MAX;

            for (int i = 1; i <= 100; i++)
            {
                if (indices[i].size() == 0)
                    continue;

                int idx = lower_bound(indices[i].begin(), indices[i].end(), l) -
                          indices[i].begin();
                int idx2 =
                    upper_bound(indices[i].begin(), indices[i].end(), r) -
                    indices[i].begin();

                if (idx2 <= idx)
                {
                    continue;
                }
                if (prev != -1)
                {
                    d = min(i - prev, d);
                }
                if (d == 1)
                    break;
                prev = i;
            }

            ans[j] = d == INT_MAX ? -1 : d;
            j++;
        }
        return ans;
    }
};