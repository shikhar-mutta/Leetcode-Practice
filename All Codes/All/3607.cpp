// Link: https://leetcode.com/problems/power-grid-maintenance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> par, rnk;
    vector<set<int>*> onlineSets;

    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (onlineSets[a]->size() < onlineSets[b]->size()) swap(a, b);
        for (int v : *onlineSets[b]) onlineSets[a]->insert(v);
        delete onlineSets[b];
        onlineSets[b] = nullptr;
        par[b] = a;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        par.assign(c + 1, 0);
        iota(par.begin(), par.end(), 0);
        onlineSets.assign(c + 1, nullptr);
        for (int i = 1; i <= c; i++) {
            onlineSets[i] = new set<int>();
            onlineSets[i]->insert(i);
        }

        for (auto& e : connections) unite(e[0], e[1]);

        vector<bool> online(c + 1, true);
        vector<int> ans;

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    int r = find(x);
                    onlineSets[r]->erase(x);
                }
            } else {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    int r = find(x);
                    if (onlineSets[r]->empty()) ans.push_back(-1);
                    else ans.push_back(*onlineSets[r]->begin());
                }
            }
        }

        return ans;
    }
};
