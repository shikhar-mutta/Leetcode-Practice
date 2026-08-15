// Link: https://leetcode.com/problems/max-stack/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) push/pop/popMax, O(1) amortized top/peekMax SC: O(n)
// Approach: a doubly linked list holds insertion order; a multimap<val, list-iterator> gives O(log n) access to the max value's node for popMax. top()/peekMax() read the ends of the respective structures.
class MaxStack {
    list<int> data;
    multimap<int, list<int>::iterator> sorted;
public:
    MaxStack() {}

    void push(int x) {
        data.push_back(x);
        auto it = std::prev(data.end());
        sorted.insert({x, it});
    }

    int pop() {
        auto listIt = std::prev(data.end());
        int val = *listIt;
        auto range = sorted.equal_range(val);
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second == listIt) { sorted.erase(it); break; }
        }
        data.pop_back();
        return val;
    }

    int top() {
        return data.back();
    }

    int peekMax() {
        return sorted.rbegin()->first;
    }

    int popMax() {
        int val = sorted.rbegin()->first;
        auto it = std::prev(sorted.end());
        auto listIt = it->second;
        sorted.erase(it);
        data.erase(listIt);
        return val;
    }
};
