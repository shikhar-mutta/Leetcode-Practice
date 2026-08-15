// Link: https://leetcode.com/problems/smallest-common-region/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string> parent;
        for (auto& r : regions) {
            for (int i = 1; i < (int)r.size(); i++) {
                parent[r[i]] = r[0];
            }
        }
        unordered_set<string> ancestors;
        string cur = region1;
        ancestors.insert(cur);
        while (parent.count(cur)) {
            cur = parent[cur];
            ancestors.insert(cur);
        }
        cur = region2;
        while (!ancestors.count(cur)) {
            cur = parent[cur];
        }
        return cur;
    }
};
