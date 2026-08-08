// Link: https://leetcode.com/problems/rank-teams-by-votes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        unordered_map<char, vector<int>> rank;
        for (char c : votes[0]) rank[c] = vector<int>(n, 0);

        for (auto& vote : votes) {
            for (int i = 0; i < n; i++) rank[vote[i]][i]++;
        }

        string teams = votes[0];
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            if (rank[a] != rank[b]) return rank[a] > rank[b];
            return a < b;
        });
        return teams;
    }
};
