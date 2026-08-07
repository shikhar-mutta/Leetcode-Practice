// Link: https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) push, O(1) others  SC: O(n)
// Approach: single queue; on push, rotate the queue so the new element ends up at the front (LIFO order)
class MyStack {
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i + 1 < (int)q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};
