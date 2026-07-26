// Link: https://leetcode.com/problems/design-a-number-container-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log q) amortized per change/find (q = total operations), thanks to
// lazy deletion in the min-heap
// SC: O(q)
// Approach: a hash map tracks each index's current number, and a second
// hash map keeps a min-heap of indices per number. change() just updates
// the index->number map and pushes the index onto that number's heap
// (stale old entries are left in place rather than removed immediately).
// find() lazily pops indices off the top of the heap whose recorded
// current number no longer matches (i.e. they were overwritten by a later
// change), until the top is genuinely still mapped to this number.
class NumberContainers {
    unordered_map<int, int> indexToNum; // index -> number
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
        numToIndices; // number -> min-heap of indices
public:
    NumberContainers() {}

    void change(int index, int number) {
        indexToNum[index] = number;
        numToIndices[number].push(index); // old entries remain but become stale
    }

    int find(int number) {
        auto it = numToIndices.find(number);
        if (it == numToIndices.end())
            return -1;
        auto& heap = it->second;
        // discard indices no longer mapped to this number
        while (!heap.empty() && indexToNum[heap.top()] != number)
            heap.pop();
        return heap.empty() ? -1 : heap.top();
    }
};
