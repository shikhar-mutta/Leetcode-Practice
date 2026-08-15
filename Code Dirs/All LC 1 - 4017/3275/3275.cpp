// Link: https://leetcode.com/problems/k-th-nearest-obstacle-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<long long> maxHeap; // holds k smallest distances, top = kth smallest
        vector<int> res;
        for (auto& q : queries) {
            long long dist = llabs((long long)q[0]) + llabs((long long)q[1]);
            if ((int)maxHeap.size() < k) {
                maxHeap.push(dist);
            } else if (dist < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(dist);
            }
            if ((int)maxHeap.size() < k) res.push_back(-1);
            else res.push_back((int)maxHeap.top());
        }
        return res;
    }
};
