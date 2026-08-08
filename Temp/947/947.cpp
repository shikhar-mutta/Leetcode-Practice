// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> parent;
        function<int(int)> find = [&](int x) {
            if (!parent.count(x)) parent[x] = x;
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        for (auto& s : stones) {
            unite(s[0], ~s[1]);
        }

        unordered_set<int> roots;
        for (auto& s : stones) roots.insert(find(s[0]));
        return (int)stones.size() - (int)roots.size();
    }
};
