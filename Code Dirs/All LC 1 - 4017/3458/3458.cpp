// Link: https://leetcode.com/problems/select-k-disjoint-special-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uf[26];
    int find(int x) { return uf[x] == x ? x : uf[x] = find(uf[x]); }

    bool maxSubstringLength(string s, int k) {
        if (k == 0) return true;
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        vector<vector<int>> positions(26);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
            positions[c].push_back(i);
        }

        auto occursInRange = [&](int c, int lo, int hi) {
            auto it = lower_bound(positions[c].begin(), positions[c].end(), lo);
            return it != positions[c].end() && *it <= hi;
        };

        for (int i = 0; i < 26; i++) uf[i] = i;
        for (int x = 0; x < 26; x++) {
            if (first[x] == -1) continue;
            for (int y = x + 1; y < 26; y++) {
                if (first[y] == -1) continue;
                int fx = first[x], lx = last[x], fy = first[y], ly = last[y];
                if (lx < fy || ly < fx) continue;
                bool xContainsY = (fx <= fy && ly <= lx);
                bool yContainsX = (fy <= fx && lx <= ly);
                bool needUnion;
                if (xContainsY && !yContainsX) {
                    needUnion = occursInRange(x, fy, ly);
                } else if (yContainsX && !xContainsY) {
                    needUnion = occursInRange(y, fx, lx);
                } else {
                    needUnion = true;
                }
                if (needUnion) {
                    int rx = find(x), ry = find(y);
                    if (rx != ry) uf[rx] = ry;
                }
            }
        }

        map<int, pair<int,int>> comp;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int r = find(c);
            if (comp.count(r)) {
                comp[r].first = min(comp[r].first, first[c]);
                comp[r].second = max(comp[r].second, last[c]);
            } else {
                comp[r] = {first[c], last[c]};
            }
        }

        vector<pair<int,int>> ivs;
        for (auto& [r, p] : comp) ivs.push_back(p);
        sort(ivs.begin(), ivs.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        int m = ivs.size();
        vector<int> parent(m, -1);
        vector<vector<int>> children(m);
        vector<int> stk;
        for (int i = 0; i < m; i++) {
            while (!stk.empty() && ivs[stk.back()].second < ivs[i].first) stk.pop_back();
            if (!stk.empty()) {
                parent[i] = stk.back();
                children[stk.back()].push_back(i);
            }
            stk.push_back(i);
        }

        vector<int> best(m, 0);
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return (ivs[a].second - ivs[a].first) < (ivs[b].second - ivs[b].first);
        });
        for (int idx : order) {
            int sumChildren = 0;
            for (int c : children[idx]) sumChildren += best[c];
            bool valid = !(ivs[idx].first == 0 && ivs[idx].second == n - 1);
            best[idx] = valid ? max(1, sumChildren) : sumChildren;
        }

        int total = 0;
        for (int i = 0; i < m; i++) if (parent[i] == -1) total += best[i];

        return k <= total;
    }
};
