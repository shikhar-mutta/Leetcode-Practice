// Link: https://leetcode.com/problems/properties-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[a] = b;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<bitset<101>> bs(n);
        for (int i = 0; i < n; i++)
            for (int v : properties[i]) bs[i][v] = 1;

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int inter = (bs[i] & bs[j]).count();
                if (inter >= k) unite(i, j);
            }
        }

        set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(find(i));
        return roots.size();
    }
};
