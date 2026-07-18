// Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> in, out;   // 'in' takes pushes, 'out' serves front

    // Move everything to 'out' only when it's empty — reverses order,
    // putting the oldest element on top. Amortized O(1).
    void shift() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        shift();
        int v = out.top();
        out.pop();
        return v;
    }

    int peek() {
        shift();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};
