// Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            res = (res + (long long)arr[i] * leftCount % MOD * rightCount) % MOD;
        }
        return (int)res;
    }
};
