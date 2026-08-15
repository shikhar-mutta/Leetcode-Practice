// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, matches = 0;
        while (i < (int)players.size() && j < (int)trainers.size()) {
            if (trainers[j] >= players[i]) {
                matches++;
                i++; j++;
            } else {
                j++;
            }
        }
        return matches;
    }
};
