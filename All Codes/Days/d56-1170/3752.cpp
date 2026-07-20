// Link: https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    // Approach:
    //  1. Calculate the sum of first n natural numbers.
    //  2. If the absolute value of target is greater than sum or (sum - target) is odd, return empty vector.
    //  3. Calculate the negative_need as (sum - target) / 2.
    //  4. Iterate from n to 1,
    //     - If negative_need is greater than or equal to i, add -i to the answer and decrease negative_need by i.
    //     - Else, add i to the answer.
    //  5. Return the answer vector.
    using ll = long long;
    vector<int> lexSmallestNegatedPerm(int n, ll target)
    {
        ll sum = 1LL * n * (n + 1) / 2;
        // If sum  -> odd then only odd target can be achieved
        if (abs(target) > sum || ((sum - target) & 1))
            return {};
        ll negative_need = (sum - target) / 2;
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = n; i >= 1; --i)
        {
            if (negative_need >= i)
            {
                ans[left++] = -i;
                negative_need -= i;
            }
            else
            {
                ans[right--] = i;
            }
        }
        return ans;
    }
};