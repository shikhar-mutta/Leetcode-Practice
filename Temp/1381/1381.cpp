// Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int maxSize;

    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if ((int)stack.size() < maxSize) stack.push_back(x);
    }

    int pop() {
        if (stack.empty()) return -1;
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; i++) stack[i] += val;
    }
};
