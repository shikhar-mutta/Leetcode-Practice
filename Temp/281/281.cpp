// Link: https://leetcode.com/problems/zigzag-iterator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per next()/hasNext()  SC: O(n) for stored vectors
// Approach: keep a queue of (vector*, index) pairs, round-robin pop from front
class ZigzagIterator {
    deque<pair<vector<int>*, int>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push_back({&v1, 0});
        if (!v2.empty()) q.push_back({&v2, 0});
    }

    int next() {
        auto [vec, idx] = q.front(); q.pop_front();
        int val = (*vec)[idx];
        if (idx + 1 < (int)vec->size()) q.push_back({vec, idx + 1});
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};
