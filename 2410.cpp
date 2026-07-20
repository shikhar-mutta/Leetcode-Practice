// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, n = players.size(), m = trainers.size();
        while (i < n && j < m)
        {
            if (players[i] <= trainers[j])
                i++;
            j++;
        }
        return i;
    }
};
