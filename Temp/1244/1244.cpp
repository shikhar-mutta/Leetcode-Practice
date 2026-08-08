// Link: https://leetcode.com/problems/design-a-leaderboard/description/

#include <bits/stdc++.h>
using namespace std;

class Leaderboard {
public:
    unordered_map<int,int> scores;

    Leaderboard() {}

    void addScore(int playerId, int score) {
        scores[playerId] += score;
    }

    int top(int K) {
        vector<int> vals;
        for (auto& [id, s] : scores) vals.push_back(s);
        sort(vals.rbegin(), vals.rend());
        int sum = 0;
        for (int i = 0; i < K && i < (int)vals.size(); i++) sum += vals[i];
        return sum;
    }

    void reset(int playerId) {
        scores.erase(playerId);
    }
};
