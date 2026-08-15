// Link: https://leetcode.com/problems/similar-string-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto similar = [](const string& a, const string& b) {
            int diff = 0;
            for (int i = 0; i < (int)a.size(); i++)
                if (a[i] != b[i] && ++diff > 2) return false;
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!similar(strs[i], strs[j])) continue;
                int ri = find(i), rj = find(j);
                if (ri != rj) parent[ri] = rj;
            }
        }
        int groups = 0;
        for (int i = 0; i < n; i++) if (find(i) == i) groups++;
        return groups;
    }
};
