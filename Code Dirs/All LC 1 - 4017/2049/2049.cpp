// Link: https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parents[i]].push_back(i);

        vector<int> subtreeSize(n, 0);
        // iterative post-order via stack
        vector<int> order;
        vector<int> stk = {0};
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            order.push_back(u);
            for (int c : children[u]) stk.push_back(c);
        }
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            int sz = 1;
            for (int c : children[u]) sz += subtreeSize[c];
            subtreeSize[u] = sz;
        }

        long long best = 0;
        int count = 0;
        for (int u = 0; u < n; u++) {
            long long score = 1;
            for (int c : children[u]) score *= subtreeSize[c];
            int rest = n - subtreeSize[u];
            if (rest > 0) score *= rest;
            if (score > best) { best = score; count = 1; }
            else if (score == best) count++;
        }
        return count;
    }
};
