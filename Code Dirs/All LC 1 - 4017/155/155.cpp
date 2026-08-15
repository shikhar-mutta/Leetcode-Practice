// Link: https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per op  SC: O(n)
// Approach: main stack + parallel min-stack tracking the running minimum at each depth
class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st.push_back(val);
        minSt.push_back(minSt.empty() ? val : min(minSt.back(), val));
    }

    void pop() {
        st.pop_back();
        minSt.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return minSt.back();
    }

private:
    vector<int> st;
    vector<int> minSt;
};
