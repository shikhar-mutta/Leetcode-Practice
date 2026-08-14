// Link: https://leetcode.com/problems/beautiful-towers-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        vector<long long> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) st.pop();
            long long sum = (long long)heights[i] * (i - (st.empty() ? -1 : st.top()));
            if (!st.empty()) sum += left[st.top()];
            left[i] = sum;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) st.pop();
            long long sum = (long long)heights[i] * ((st.empty() ? n : st.top()) - i);
            if (!st.empty()) sum += right[st.top()];
            right[i] = sum;
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, left[i] + right[i] - heights[i]);
        return ans;
    }
};
