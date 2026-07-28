// Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
//  Approach: dp[i][diff] = number of "weak" arithmetic subsequences
//  (length >= 2) ending at index i with common difference diff. For each
//  pair (j,i), dp[i][diff] += dp[j][diff] + 1 (extending j's subsequences
//  plus the new 2-length pair); only dp[j][diff] (length>=2 already)
//  contributes to actual answer (length >= 3) slices.
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<long, vector<int>> map;

        for (int i = 0; i < n; i++)
        {
            long temp = nums[i];
            if (!map.count(temp))
            {
                map[temp] = vector<int>();
            }
            map[temp].push_back(i);
        }

        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long a = 2L * nums[i] - nums[j];
                if (map.count(a))
                {
                    for (int k : map[a])
                    {
                        if (k < i)
                        {
                            dp[i][j] += dp[k][i] + 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};