// Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        vector<int> st;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.back()] > arr[i])
            {
                st.pop_back();
            }
            st.push_back(i);
            if (st.size() == 1)
            {
                dp[i] = (arr[i]) * (i + 1);
            }
            else
            {
                int val = st[st.size() - 2];
                dp[i] = (arr[i] * (i - val) + dp[val]) % mod;
            }
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};