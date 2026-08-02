// Link: https://leetcode.com/problems/find-the-sum-of-subsequence-powers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * log(n))  SC: O(n^2)
// Approach: For each unique difference between the elements of nums, we can count the number of subsequences of length k that have a minimum difference of at least that value. We can do this using a recursive function with memoization. The final answer is the sum of the products of each unique difference and the number of subsequences that have that difference as their minimum difference.
long long dp[51][51];
class Solution
{
public:
    int mod = 1e9 + 7;
    long long rec(int ind, int cnt, vector<int> &nums, int x)
    {
        if (cnt == 0)
            return 1;
        if (ind >= nums.size())
            return 0;
        if (dp[ind][cnt] != -1)
            return dp[ind][cnt];
        int ans = rec(ind + 1, cnt, nums, x);
        ans %= mod;
        auto a = lower_bound(nums.begin() + ind + 1, nums.end(), nums[ind] + x);
        ans += rec(a - nums.begin(), cnt - 1, nums, x);
        ans %= mod;
        return dp[ind][cnt] = ans;
    }
    int sumOfPowers(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                st.insert(nums[j] - nums[i]);
            }
        }
        vector<int> dif(st.begin(), st.end());
        vector<long long> cnt(dif.size());
        for (int i = 0; i < dif.size(); i++)
        {
            memset(dp, -1, sizeof(dp));
            cnt[i] = rec(0, k, nums, dif[i]);
        }

        long long ans = 0;
        for (int i = 0; i < dif.size(); i++)
        {
            long long c = cnt[i] - (i + 1 < dif.size() ? cnt[i + 1] : 0);
            ans += c * dif[i];
            ans %= mod;
        }
        return ans;
    }
};
