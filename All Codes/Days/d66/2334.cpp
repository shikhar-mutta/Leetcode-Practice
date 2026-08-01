// Link: https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(k)
//  Approach: monotonic stack. For each element, find the largest rectangle
//  with that element as the smallest height. If the area of that rectangle
//  exceeds the threshold, update the answer with the width of that rectangle.
class Solution
{
public:
    using ll = long long;
    int validSubarraySize(vector<int> &nums, int tt)
    {
        int n = nums.size();
        vector<ll> arr(n + 2);
        arr[0] = 0;
        arr[n + 1] = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i + 1] = nums[i];
        }
        vector<int> st;
        st.push_back(0);
        ll mn = INT_MAX;
        for (int i = 1; i <= n + 1; i++)
        {
            while (!st.empty() && arr[i] < arr[st.back()])
            {
                ll h = arr[st.back()];
                st.pop_back();
                ll w = i - st.back() - 1;
                if (h * w > tt)
                {
                    mn = min(mn, w);
                }
            }
            st.push_back(i);
        }
        return mn == INT_MAX ? -1 : mn;
    }
};