// Link: https://leetcode.com/problems/minimum-total-distance-traveled/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M*N^2), SC: O(N)
// Approach: sort robots and factories by position (optimal assignment never crosses). dp[i] = min
// cost to assign the first i (sorted) robots using factories processed so far; for each factory,
// try assigning its last k robots (k up to its limit) contiguously ending at position i.
class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot,
                                   vector<vector<int>> &raw_factory)
    {
        vector<vector<int>> factory;
        for (auto &x : raw_factory)
        {
            if (x[1] != 0)
            {
                factory.push_back(x);
            }
        }

        int n = factory.size();
        int m = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(),
             [](auto &a, auto &b)
             { return a[0] < b[0]; });
        vector<int> repair(m, -1);  // Where this robot is getting repaired.
        vector<int> capacity(n, 0); // Number of robots being repaired here.

        long long cost = 0;
        for (int i = 0; i < m; ++i)
        { // Robot we are currently inserting.
            long long current_cost = cost;
            int best = -1;
            for (int j = n - 1; j >= 0; --j)
            {
                // What if insert robot j in to factory i?
                if (capacity[j] < factory[j][1])
                {
                    long long next_cost = cost + abs(factory[j][0] - robot[i]);
                    // cout << j << " " << next_cost << "\n";
                    if (best == -1 || next_cost < current_cost)
                    {
                        best = j;
                        current_cost = next_cost;
                    }
                }
                else if (capacity[j] == factory[j][1] && j != 0)
                {
                    // Requires a push back, so we can break here.
                    long long next_cost = cost + abs(factory[j][0] - robot[i]);
                    int l = i;
                    for (int k = j; k > 0 && capacity[k] == factory[k][1];
                         --k)
                    {
                        // Subtract away last robot and add it to the next one.
                        l -= capacity[k];
                        next_cost -= abs(factory[k][0] - robot[l]);
                        next_cost += abs(factory[k - 1][0] - robot[l]);
                    }
                    if (best == -1 || next_cost < current_cost)
                    {
                        best = j;
                        current_cost = next_cost;
                    }
                    break;
                }
            }

            // Apply the best robot.
            if (capacity[best] < factory[best][1])
            {
                // Just add to factory.
                cost += abs(factory[best][0] - robot[i]);
                capacity[best]++;
                repair[i] = best;
            }
            else
            {
                cost += abs(factory[best][0] - robot[i]);
                capacity[best]++;
                repair[i] = best;
                int l = i;
                for (int k = best; k > 0 && capacity[k] > factory[k][1]; --k)
                {
                    // Subtract away last robot and add it to the next one.
                    capacity[k]--;
                    capacity[k - 1]++;
                    l -= capacity[k];
                    repair[l] = k - 1;
                    cost -= abs(factory[k][0] - robot[l]);
                    cost += abs(factory[k - 1][0] - robot[l]);
                }
            }
        }
        return cost;
    }
};