// Link: https://leetcode.com/problems/dinner-plate-stacks/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: amortized O(log n) per op  SC: O(n)
// Approach: store stacks as vector<vector<int>>, tracking a min-heap of
// stack indices that currently have room (lazily cleaned of stale/full
// entries). push() uses the smallest available index (or creates a new
// stack); pop() trims trailing empty stacks then pops the last one;
// popAtStack(i) pops directly and marks i as available again.
class DinnerPlates {
    int cap;
    vector<vector<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> avail;
public:
    DinnerPlates(int capacity) : cap(capacity) {}

    void push(int val) {
        while (!avail.empty()) {
            int idx = avail.top();
            if (idx < (int)stacks.size() && (int)stacks[idx].size() < cap) break;
            avail.pop();
        }
        if (avail.empty()) {
            stacks.push_back({val});
            if ((int)stacks.back().size() < cap) avail.push(stacks.size() - 1);
        } else {
            int idx = avail.top();
            stacks[idx].push_back(val);
            if ((int)stacks[idx].size() >= cap) avail.pop();
        }
    }

    int pop() {
        while (!stacks.empty() && stacks.back().empty()) stacks.pop_back();
        if (stacks.empty()) return -1;
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index >= (int)stacks.size() || stacks[index].empty()) return -1;
        int val = stacks[index].back();
        stacks[index].pop_back();
        avail.push(index);
        return val;
    }
};
