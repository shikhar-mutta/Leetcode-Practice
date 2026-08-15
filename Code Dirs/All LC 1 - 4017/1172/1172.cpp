// Link: https://leetcode.com/problems/dinner-plate-stacks/description/

#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
    int capacity;
    vector<vector<int>> stacks;
    set<int> available;

    void trimEmpty() {
        while (!stacks.empty() && stacks.back().empty()) stacks.pop_back();
    }
public:
    DinnerPlates(int capacity_) : capacity(capacity_) {}

    void push(int val) {
        int idx;
        if (!available.empty()) {
            idx = *available.begin();
        } else {
            idx = stacks.size();
            stacks.push_back({});
        }
        if (idx >= (int)stacks.size()) stacks.resize(idx + 1);
        stacks[idx].push_back(val);
        if ((int)stacks[idx].size() >= capacity) available.erase(idx);
        else available.insert(idx);
    }

    int pop() {
        trimEmpty();
        if (stacks.empty()) return -1;
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index >= (int)stacks.size() || stacks[index].empty()) return -1;
        int val = stacks[index].back();
        stacks[index].pop_back();
        available.insert(index);
        trimEmpty();
        return val;
    }
};
