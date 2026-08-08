// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);
        for (auto& e : edges) hasIncoming[e[1]] = true;
        vector<int> res;
        for (int i = 0; i < n; i++) if (!hasIncoming[i]) res.push_back(i);
        return res;
    }
};
