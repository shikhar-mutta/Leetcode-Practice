// Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: union-find over the adjacency matrix, count distinct roots
class Solution {
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int ri = find(i), rj = find(j);
                    if (ri != rj) { parent[ri] = rj; count--; }
                }
            }
        }
        return count;
    }
};
