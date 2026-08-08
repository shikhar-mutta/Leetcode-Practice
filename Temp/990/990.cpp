// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };

        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int a = eq[0]-'a', b = eq[3]-'a';
                parent[find(a)] = find(b);
            }
        }
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0]-'a', b = eq[3]-'a';
                if (find(a) == find(b)) return false;
            }
        }
        return true;
    }
};
