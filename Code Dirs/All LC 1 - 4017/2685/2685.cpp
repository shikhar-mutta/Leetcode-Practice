// Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto &e : edges) {
            int ru = find(e[0]), rv = find(e[1]);
            if (ru != rv) parent[ru] = rv;
        }

        unordered_map<int, long long> nodeCount, edgeCount;
        for (int i = 0; i < n; i++) nodeCount[find(i)]++;
        for (auto &e : edges) edgeCount[find(e[0])]++;

        int ans = 0;
        for (auto &[root, cnt] : nodeCount) {
            long long needed = cnt * (cnt - 1) / 2;
            if (edgeCount[root] == needed) ans++;
        }
        return ans;
    }
};
