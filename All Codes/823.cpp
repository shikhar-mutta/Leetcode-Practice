// Link: https://leetcode.com/problems/binary-trees-with-factors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n), where n is the length of arr.
    // Approach: Sort the array and use dynamic programming to count the number of binary trees that can be formed with each element as the root. For each element, check all pairs of factors that multiply to that element and use previously computed counts for those factors to calculate the count for the current element.
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        const long long MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, long long> dp; // value -> number of trees rooted with that value
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long ways = 1;
            for (int j = 0; j < i && (long long)arr[j] * arr[j] <= arr[i]; j++)
            {
                if (arr[i] % arr[j] != 0)
                    continue;
                int other = arr[i] / arr[j];
                auto it = dp.find(other);
                if (it == dp.end())
                    continue;
                long long prod = dp[arr[j]] * it->second % MOD;
                if (other != arr[j])
                    prod = prod * 2 % MOD; // left/right swap
                ways = (ways + prod) % MOD;
            }
            dp[arr[i]] = ways;
            total = (total + ways) % MOD;
        }
        return (int)total;
    }
};
