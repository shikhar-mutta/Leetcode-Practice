// Link: https://leetcode.com/problems/campus-bikes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<array<int,3>> triples;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                triples.push_back({d, i, j});
            }
        }
        sort(triples.begin(), triples.end());
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        int assigned = 0;
        for (auto& t : triples) {
            int i = t[1], j = t[2];
            if (res[i] != -1 || bikeUsed[j]) continue;
            res[i] = j;
            bikeUsed[j] = true;
            assigned++;
            if (assigned == n) break;
        }
        return res;
    }
};
