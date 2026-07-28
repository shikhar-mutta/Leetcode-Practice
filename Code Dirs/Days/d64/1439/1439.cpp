// Link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> cur = mat[0];
        int n = mat.size(), m = mat[0].size();
        for (int r = 1; r < n; r++) {
            vector<int> nxt;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            for (int i = 0; i < (int)cur.size() && i < k; i++)
                pq.push({cur[i] + mat[r][0], i * m + 0});
            vector<char> visited(cur.size() * m, 0);
            while (!pq.empty() && (int)nxt.size() < k) {
                auto [sum, code] = pq.top(); pq.pop();
                int i = code / m, j = code % m;
                nxt.push_back(sum);
                if (j + 1 < m && !visited[i * m + j + 1]) {
                    visited[i * m + j + 1] = 1;
                    pq.push({cur[i] + mat[r][j + 1], i * m + j + 1});
                }
            }
            cur = nxt;
        }
        return cur[k - 1];
    }
};
