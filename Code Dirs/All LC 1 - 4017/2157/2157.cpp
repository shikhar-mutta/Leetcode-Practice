// Link: https://leetcode.com/problems/groups-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int> parent;
    int find(int x) {
        if (!parent.count(x)) parent[x] = x;
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int,long long> maskCount;
        for (auto& w : words) {
            int m = 0;
            for (char c : w) m |= (1 << (c - 'a'));
            maskCount[m]++;
            find(m);
        }

        for (auto& [m, cnt] : maskCount) {
            for (int b = 0; b < 26; b++) {
                if (!((m >> b) & 1)) {
                    int nm = m | (1 << b);
                    if (maskCount.count(nm)) unite(m, nm);
                }
            }
            for (int b = 0; b < 26; b++) {
                if ((m >> b) & 1) {
                    int nm = m & ~(1 << b);
                    if (maskCount.count(nm)) unite(m, nm);
                    int base = nm;
                    for (int c = 0; c < 26; c++) {
                        if (c == b) continue;
                        if ((base >> c) & 1) continue;
                        int candidate = base | (1 << c);
                        if (maskCount.count(candidate)) unite(m, candidate);
                    }
                }
            }
        }

        unordered_map<int,long long> groupSize;
        for (auto& [m, cnt] : maskCount) {
            int r = find(m);
            groupSize[r] += cnt;
        }
        int numGroups = groupSize.size();
        long long maxSize = 0;
        for (auto& [r, sz] : groupSize) maxSize = max(maxSize, sz);
        return {numGroups, (int)maxSize};
    }
};
