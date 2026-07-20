// Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int winCount[100001];
    int lossCount[100001];

public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        fill(winCount, winCount + 100001, 0);
        fill(lossCount, lossCount + 100001, 0);

        int maxPlayer = 1;
        for (auto &match : matches)
        {
            winCount[match[0]]++;
            lossCount[match[1]]++;
            maxPlayer = max(maxPlayer, match[0]);
            maxPlayer = max(maxPlayer, match[1]);
        }

        vector<vector<int>> answer(2);
        for (int i = 1; i <= maxPlayer; i++)
        {
            // cout << i << " " << winCount[i] << " " << lossCount[i] << "\n";
            if (winCount[i] > 0 && lossCount[i] == 0)
            {
                answer[0].push_back(i);
            }
            else if (lossCount[i] == 1)
            {
                answer[1].push_back(i);
            }
        }

        return answer;
    }
};
