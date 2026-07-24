// Link: https://leetcode.com/problems/find-the-winner-of-an-array-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    //   Approach:
    //     1. We will keep track of the current winner and the number of wins.
    //     2. We will iterate through the array and for each element, we will compare it with the current winner.
    //     3. If the current element is greater than the current winner, we will update the current winner and reset the number of wins to 1.
    //     4. If the current element is less than the current winner, we will increment the number of wins.
    //     5. If the number of wins is equal to k, we will return the current winner.
    //     6. If we reach the end of the array and the number of wins is less than k, we will return the current winner.
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();

        int wins = 0;
        int winner = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (winner > arr[i])
            {
                wins++;
            }
            else
            {
                winner = arr[i];
                wins = 1;
            }
            if (wins == k)
                return winner;
        }

        return winner;
    }
};