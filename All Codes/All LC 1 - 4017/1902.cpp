// Link: https://leetcode.com/problems/depth-of-bst-given-insertion-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        map<int, int> depth;
        depth[INT_MIN] = 0;
        depth[INT_MAX] = 0;
        int best = 0;
        for (int x : order) {
            auto it = depth.lower_bound(x);
            auto succ = it;
            auto pred = prev(it);
            int d = max(pred->second, succ->second) + 1;
            depth[x] = d;
            best = max(best, d);
        }
        return best;
    }
};
