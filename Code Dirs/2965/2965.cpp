// Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> ans(2);
        int n = grid.size();
        int total = n * n;
        long long sum = 0, sqSum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += grid[i][j];
                sqSum += (long long)grid[i][j] * grid[i][j];
            }
        }
        long long t = total;
        long long actualSum = t * (t + 1) / 2;
        long long actualSqSum = t * (t + 1) * (2 * t + 1) / 6;
        long long diff = sum - actualSum;
        long long sqDiff = sqSum - actualSqSum;
        int repeated = (int)((sqDiff / diff + diff) / 2);
        int missing = (int)(repeated - diff);
        ans[0] = repeated;
        ans[1] = missing;
        return ans;
    }
};
