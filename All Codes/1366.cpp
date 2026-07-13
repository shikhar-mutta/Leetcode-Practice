// Link: https://leetcode.com/problems/rank-teams-by-votes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of teams.
    // SC: O(n) for storing the count of votes for each team.
    // Approach:
    // 1. Count the number of votes for each team at each position.
    // 2. Sort the teams based on their votes at each position.
    string rankTeams(vector<string> &votes)
    {
        int n = votes[0].size();
        // cnt[c][p] = how many voters put team c at position p
        vector<vector<int>> cnt(26, vector<int>(n, 0));
        for (auto &v : votes)
            for (int p = 0; p < n; p++)
                cnt[v[p] - 'A'][p]++;
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char a, char b)
             {
            if (cnt[a - 'A'] != cnt[b - 'A'])
                return cnt[a - 'A'] > cnt[b - 'A'];
            return a < b; });
        return res;
    }
};
