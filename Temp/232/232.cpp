// Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per op  SC: O(n)
// Approach: two stacks — in for pushes, out for pops/peeks; transfer in->out (reversing order) only
// when out is empty, so each element crosses at most once
class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        moveIfNeeded();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        moveIfNeeded();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }

private:
    stack<int> in, out;
    void moveIfNeeded() {
        if (out.empty()) {
            while (!in.empty()) { out.push(in.top()); in.pop(); }
        }
    }
};
