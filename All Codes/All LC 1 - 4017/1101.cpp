// Link: https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        int components = n;
        for (auto& log : logs) {
            int ra = find(log[1]), rb = find(log[2]);
            if (ra != rb) {
                parent[ra] = rb;
                components--;
                if (components == 1) return log[0];
            }
        }
        return -1;
    }
};
