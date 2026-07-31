// Link: https://leetcode.com/problems/odd-even-jump/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
//  Approach: We can use a greedy approach to solve this problem. We can keep track of the next higher and next lower indices for each index in the array. We can use a stack to keep track of the indices in the array and update the next higher and next lower indices accordingly. We can then use dynamic programming to keep track of the odd and even jumps for each index in the array. The final answer will be the number of indices that can reach the end of the array using odd jumps.
class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextHigher(n, -1), nextLower(n, -1);
        // Next Higher
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({arr[i], i});
        sort(v.begin(), v.end());
        stack<int> st;
        for (auto &[val, idx] : v)
        {
            while (!st.empty() && idx > st.top())
            {
                nextHigher[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        // Next Lower
        v.clear();
        for (int i = 0; i < n; i++)
            v.push_back({-arr[i], i});
        sort(v.begin(), v.end());
        while (!st.empty())
            st.pop();
        for (auto &[val, idx] : v)
        {
            while (!st.empty() && idx > st.top())
            {
                nextLower[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nextHigher[i] != -1)
                odd[i] = even[nextHigher[i]];
            if (nextLower[i] != -1)
                even[i] = odd[nextLower[i]];
        }
        int ans = 0;
        for (bool x : odd)
            ans += x;
        return ans;
    }
};