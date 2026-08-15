// Link: https://leetcode.com/problems/smallest-string-with-swaps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        for (auto& p : pairs) {
            int ra = find(p[0]), rb = find(p[1]);
            if (ra != rb) parent[ra] = rb;
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[find(i)].push_back(i);

        string res = s;
        for (auto& [root, indices] : groups) {
            vector<int> idx = indices;
            string chars;
            for (int i : idx) chars += s[i];
            sort(chars.begin(), chars.end());
            sort(idx.begin(), idx.end());
            for (int i = 0; i < (int)idx.size(); i++) res[idx[i]] = chars[i];
        }
        return res;
    }
};
