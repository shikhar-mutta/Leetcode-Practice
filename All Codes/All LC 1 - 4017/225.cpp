// Link: https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}

    // Push x, then rotate so the newest element sits at the front (LIFO via FIFO).
    void push(int x) {
        q.push(x);
        for (int i = (int)q.size() - 1; i > 0; i--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int v = q.front();
        q.pop();
        return v;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
