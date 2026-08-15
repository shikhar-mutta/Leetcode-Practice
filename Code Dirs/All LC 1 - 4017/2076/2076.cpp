// Link: https://leetcode.com/problems/process-restricted-friend-requests/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<bool> res;
        for (auto& req : requests) {
            int ra = find(req[0]), rb = find(req[1]);
            if (ra == rb) { res.push_back(true); continue; }
            bool violates = false;
            for (auto& r : restrictions) {
                int rx = find(r[0]), ry = find(r[1]);
                if ((rx == ra && ry == rb) || (rx == rb && ry == ra)) { violates = true; break; }
            }
            if (violates) {
                res.push_back(false);
            } else {
                parent[ra] = rb;
                res.push_back(true);
            }
        }
        return res;
    }
};
