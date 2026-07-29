// Link: https://leetcode.com/problems/make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m log m)  SC: O(n) states
//  Approach: DP over "last value placed" -> minimum replacements so far,
//  using a map for compactness. For each element of arr1, either keep it
//  (if it exceeds the current last value) or replace it with the
//  smallest value from sorted arr2 that exceeds the last value (costing
//  one more operation). Collapse to the best (min ops) state per last
//  value each step; if no transition survives, it's impossible.
class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        vector<int> dp(n, -1);
        sort(arr2.begin(), arr2.end());
        auto result = unique(arr2.begin(), arr2.end());
        arr2.erase(result, arr2.end());
        int ans = f1(arr1, arr2, 0, n, dp);
        return ans == INT_MAX ? -1 : ans;
    }
    int f1(vector<int> &arr1, vector<int> &arr2, int i, int n,
           vector<int> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int ans = INT_MAX;
        int pre = i == 0 ? INT_MIN : arr1[i - 1];
        auto find = upper_bound(arr2.begin(), arr2.end(), pre);
        for (int j = i, k = 0; j <= n; j++, k++)
        {
            if (j == n)
            {
                ans = min(ans, k);
            }
            else
            {
                if (pre < arr1[j])
                {
                    int next = f1(arr1, arr2, j + 1, n, dp);
                    if (next != INT_MAX)
                    {
                        ans = min(ans, k + next);
                    }
                }
                if (find != arr2.end())
                {
                    pre = *find;
                    find++;
                }
                else
                {
                    break;
                }
            }
        }
        return dp[i] = ans;
    }
};
