// Link: https://leetcode.com/problems/count-unhappy-friends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> partner(n);
        for (auto& p : pairs) {
            partner[p[0]] = p[1];
            partner[p[1]] = p[0];
        }

        vector<unordered_map<int,int>> rank(n);
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < (int)preferences[x].size(); i++) {
                rank[x][preferences[x][i]] = i;
            }
        }

        int count = 0;
        for (int x = 0; x < n; x++) {
            int y = partner[x];
            int xyRank = rank[x][y];
            bool unhappy = false;
            for (int i = 0; i < xyRank; i++) {
                int u = preferences[x][i];
                int v = partner[u];
                if (rank[u][x] < rank[u][v]) { unhappy = true; break; }
            }
            if (unhappy) count++;
        }
        return count;
    }
};
