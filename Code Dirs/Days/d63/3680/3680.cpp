// Link: https://leetcode.com/problems/generate-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: The idea is to generate a schedule for n players such that each player plays against every other player exactly once. We can achieve this by creating pairs of players in a systematic way. For even n, we can pair players in a round-robin fashion, while for odd n, we can use a similar approach but with an additional player who sits out each round. We continue this process until all pairs have been generated.
// The schedule is generated in such a way that each player plays against every other player exactly once, and the order of matches is determined by the pairing strategy. The algorithm ensures that all possible pairs are covered without repetition, and it handles both even and odd numbers of players appropriately.
class Solution
{

public:
    vector<vector<int>> generateSchedule(int n)
    {
        vector<vector<int>> ans;

        if (n <= 4)
            return ans;

        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
                ans.push_back({i, i + 1});
            for (int i = 0; i < n; i += 2)
                ans.push_back({i + 1, i});

            for (int i = 1; i < n; i += 2)
                ans.push_back({i, (i + 1) % n});
            for (int i = 1; i < n; i += 2)
                ans.push_back({(i + 1) % n, i});
        }
        else
        {
            for (int i = 0; i < 2 * n; i += 2)
            {
                ans.push_back({i % n, (i + 1) % n});
            }

            for (int i = 0; i < 2 * n; i += 2)
            {
                ans.push_back({(i + 1) % n, i % n});
            }
        }

        for (int gap = 2; gap < (n + 1) / 2; gap++)
        {
            int start = ans.back()[0] + 1;

            for (int i = start; i < start + n; i++)
            {
                ans.push_back({i % n, (i + gap) % n});
            }

            start = (ans.back()[1] - 1 + n) % n;

            for (int i = start; i < start + n; i++)
            {
                ans.push_back({(i + gap) % n, i % n});
            }
        }

        if (n % 2 == 0)
        {
            int gap = n / 2;
            int start = (ans.back()[0] - 1 + n) % n;

            for (int i = start; i < start + n; i++)
            {
                ans.push_back({i % n, (i + gap) % n});
            }
        }

        return ans;
    }
};
