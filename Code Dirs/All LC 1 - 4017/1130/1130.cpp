// Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        int res = 0;
        for (int x : arr) {
            while (st.top() <= x) {
                int mid = st.top(); st.pop();
                res += mid * min(st.top(), x);
            }
            st.push(x);
        }
        while (st.size() > 2) {
            int mid = st.top(); st.pop();
            res += mid * st.top();
        }
        return res;
    }
};
