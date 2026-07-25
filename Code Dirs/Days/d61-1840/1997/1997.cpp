// Link: https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of rooms
// SC: O(n) where n is the number of rooms
//  Approach:
//  1. We will use dynamic programming to store the number of days required to visit each room
//  2. We will iterate through the rooms and for each room, we will calculate the number of days required to visit it based on the previous rooms and the nextVisit array
//  3. Finally, we will return the number of days required to visit the last room
class Solution
{
    const int MOD = 1e9 + 7;

public:
    int firstDayBeenInAllRooms(vector<int> &nextVisit)
    {
        int n = nextVisit.size();
        int dp[n];
        dp[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            dp[i + 1] = (2LL * dp[i] - dp[nextVisit[i]] + 2 + MOD) % MOD;
        }
        return dp[n - 1] % MOD;
    }
};