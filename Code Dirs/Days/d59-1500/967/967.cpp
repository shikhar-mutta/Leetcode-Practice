// Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), SC: O(n)
    //  Approach: DFS
    //  1. We will use DFS to generate all the numbers with the same consecutive differences
    //  2. We will start with the first digit and then recursively generate the next digits
    //  3. We will keep track of the remaining digits to be generated and the current number being generated
    //  4. If the remaining digits to be generated is 0, we will add the current number to the result vector
    //  5. Finally, we will return the result vector after sorting it in ascending order
    void dfs(int cur, int remaining, int k, vector<int> &result)
    {
        if (remaining == 0)
        {
            result.push_back(cur);
            return;
        }
        int lastDigit = cur % 10;
        if (lastDigit + k <= 9)
            dfs(cur * 10 + lastDigit + k, remaining - 1, k, result);
        if (k != 0 && lastDigit - k >= 0)
            dfs(cur * 10 + lastDigit - k, remaining - 1, k, result);
    }

    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> result;
        for (int d = 1; d <= 9; d++)
            dfs(d, n - 1, k, result);
        sort(result.begin(), result.end());
        return result;
    }
};
