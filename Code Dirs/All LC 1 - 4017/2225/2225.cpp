// Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        unordered_map<int,int> losses;
        for (auto& m : matches) {
            players.insert(m[0]);
            players.insert(m[1]);
            losses[m[1]]++;
        }
        vector<int> zero, one;
        for (int p : players) {
            if (!losses.count(p)) zero.push_back(p);
            else if (losses[p] == 1) one.push_back(p);
        }
        return {zero, one};
    }
};
