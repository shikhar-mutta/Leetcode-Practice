// Link: https://leetcode.com/problems/find-champion-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (auto& e : edges) indeg[e[1]]++;
        int champ = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) { champ = i; cnt++; }
        }
        return cnt == 1 ? champ : -1;
    }
};
