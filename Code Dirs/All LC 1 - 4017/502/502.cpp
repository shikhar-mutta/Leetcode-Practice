// Link: https://leetcode.com/problems/ipo/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort projects by capital requirement; at each step, push all
// affordable projects' profits into a max-heap, pick the best one
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return capital[a] < capital[b]; });

        priority_queue<int> maxHeap;
        int ptr = 0;
        for (int i = 0; i < k; i++) {
            while (ptr < n && capital[idx[ptr]] <= w) {
                maxHeap.push(profits[idx[ptr]]);
                ptr++;
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
