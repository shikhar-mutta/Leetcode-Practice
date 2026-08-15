// Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (ra < rb) parent[rb] = ra;
            else parent[ra] = rb;
        };
        for (int i = 0; i < (int)s1.size(); i++) unite(s1[i]-'a', s2[i]-'a');

        string res;
        for (char c : baseStr) res += ('a' + find(c-'a'));
        return res;
    }
};
