// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogm)
    // SC: O(1)
    // Approach:
    //  1. Sort both players and trainers in ascending order.
    //  2. Use two pointers to iterate through both arrays.
    //  3. If the current player can be matched with the current trainer, move both
    //     pointers to the next player and trainer.
    //  4. If the current player cannot be matched with the current trainer, move
    //     the trainer pointer to the next trainer.
    //  5. Return the number of matched players.
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
