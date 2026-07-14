// Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
//  Approach:
//   1. Find the maximum value in the 'piles' array.
//   2. Create a frequency array of size 'max + 1' and store the frequency of each value in the 'piles' array.
//   3. Iterate from the maximum value to 0 and keep track of the number of chances left and the turn of the player
//   4. If the current value has a frequency greater than 0, check if it's the player's turn to pick the coin. If it is, add the value to the total coins and decrement the chance. If it's not the player's turn, just decrement the frequency of the current value. If the frequency is 0, move to the next lower value. Repeat until all chances are used up.

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int max = 0;
        int n = piles.size();

        for (int i : piles)
        {
            if (max < i)
                max = i;
        }
        vector<int> freq(max + 1, 0);

        for (int i : piles)
        {
            freq[i]++;
        }
        int coins = 0;
        int chance = n / 3;
        int turn = 1;
        int i = max;
        while (chance != 0)
        {
            if (freq[i] > 0)
            {
                if (turn == 1)
                    turn = 0;
                else
                {
                    chance--;
                    turn = 1;
                    coins += i;
                }
                freq[i]--;
            }
            else
            {
                i--;
            }
        }
        return coins;
    }
};