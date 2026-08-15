// Link: https://leetcode.com/problems/k-th-nearest-obstacle-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log k), SC: O(k)
// Approach: Maintain a max-heap of the k smallest Manhattan distances seen
// so far. Once k obstacles have appeared, the heap's top is the k-th
// nearest; for each subsequent obstacle, replace the current max in the
// heap if the new distance is smaller, keeping the heap always holding the
// k smallest distances.
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& qs, int k) {
        int n = qs.size();

        vector<int> ans(n);
        priority_queue<int> pq;
        int fst = min(k, n);
        for (int i = 0; i < fst; i++) {
            ans[i] = -1;
            pq.push(abs(qs[i][0]) + abs(qs[i][1]));
        }

        if (k <= n)
            ans[k - 1] = pq.top();

        for (int i = k; i < n; i++) {
            int d = abs(qs[i][0]) + abs(qs[i][1]);
            if (d < pq.top()) {
                pq.pop();
                pq.push(d);
            }
            ans[i] = pq.top();
        }

        return ans;
    }
};
