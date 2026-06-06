// Link: https://leetcode.com/problems/find-the-number-of-winning-players/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*11) = O(n) SC: O(n*11) = O(n)
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        vector<vector<int>> arr(n, vector<int>(11, 0));
        int ans = 0;
        for (int i = 0; i < pick.size(); i++)
        {
            int p = pick[i][0]; // player
            int c = pick[i][1]; // color
            arr[p][c]++;        // count the number of times player p has picked color c
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= 10; j++)
                if (arr[i][j] > i)
                {
                    ans++;
                    break;
                }

        return ans;
    }
};