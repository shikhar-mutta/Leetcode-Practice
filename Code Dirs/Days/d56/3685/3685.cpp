// Link: https://leetcode.com/problems/subsequence-sum-after-capping-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*k)
    // SC: O(k)
    // Approach:
    //  1. We can use dynamic programming to solve this problem.
    //  2. We can use a bitset to keep track of the possible sums that can be formed using the elements of the array.
    //  3. We can iterate through the array and for each element, we can update the bitset to include the new sums that can be formed by adding the current element to the existing sums.
    //  4. We can also keep track of the number of elements that are greater than the current element and use that to determine if we can form the required sum after capping the elements.
    //  5. Finally, we can return the result for each element in the array
    //     by checking if the required sum can be formed using the elements of the array after   capping the elements.
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> byVal(n + 1, 0);
        for (int v : nums)
            byVal[min(v, n)]++;
        bitset<4001> dp;
        dp[0] = 1;
        int gt = n;
        vector<bool> ans(n);
        for (int x = 1; x <= n; x++)
        {
            for (int c = 0; c < byVal[x]; c++)
                dp |= dp << x;
            gt -= byVal[x];
            bool ok = false;
            for (long long j = 0; j <= gt && j * x <= k && !ok; j++)
                if (dp[k - j * x])
                    ok = true;
            ans[x - 1] = ok;
        }
        return ans;
    }
};
