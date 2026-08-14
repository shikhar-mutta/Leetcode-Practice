// Link: https://leetcode.com/problems/substring-xor-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<long long, pair<int,int>> pos;
        for (int len = 1; len <= 30 && len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                long long val = 0;
                for (int k = 0; k < len; k++) val = val * 2 + (s[start + k] - '0');
                if (!pos.count(val)) pos[val] = {start, start + len - 1};
            }
        }

        vector<vector<int>> ans;
        for (auto &q : queries) {
            long long target = (long long)q[0] ^ (long long)q[1];
            if (pos.count(target)) {
                auto &[l, r] = pos[target];
                ans.push_back({l, r});
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};
