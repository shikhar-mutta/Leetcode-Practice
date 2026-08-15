// Link: https://leetcode.com/problems/node-with-highest-edge-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for (int i = 0; i < n; i++) score[edges[i]] += i;
        int best = 0;
        for (int i = 1; i < n; i++) if (score[i] > score[best]) best = i;
        return best;
    }
};
