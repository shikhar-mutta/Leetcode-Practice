// Link: https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> ans;
        vector<bool> visited(n + 1, false);
        int curr = 0, step = 0;
        while (!visited[curr])
        {
            visited[curr] = true;
            step++;
            curr = (curr + step * k) % n;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i - 1])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
