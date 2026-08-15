// Link: https://leetcode.com/problems/minimum-time-to-transport-all-individuals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * m * n) where n is the number of people and m is the number of stages. The algorithm explores all possible combinations of people to transport and all stages, leading to exponential growth in the number of states. The priority queue operations add a logarithmic factor, but the dominant term is the exponential growth due to the bitmasking approach.
// SC: O(2^n * m) for storing the minimum time for each state
// Approach: The solution uses a priority queue to implement a modified Dijkstra's algorithm. It explores all possible states of transporting people across stages, using bitmasking to represent which individuals have been transported. The algorithm calculates the minimum time required to transport all individuals while considering the constraints of the problem.
class Solution
{
public:
    double minTime(int n, int k, int m, vector<int> &time,
                   vector<double> &mul)
    {
        const int stage_base = 2;
        const int mask_base = stage_base * m;
        const int final_mask = (1 << n) - 1;
        const int total_state = final_mask * mask_base + m * stage_base + 3;
        priority_queue<pair<double, int>, vector<pair<double, int>>,
                       greater<pair<double, int>>>
            min_heap;
        vector<double> dist(total_state, DBL_MAX);

        vector<int> mask_time(final_mask + 1);
        for (size_t mask = final_mask; mask > 0;
             mask = (mask - 1) & final_mask)
        {
            if (popcount(mask) > k)
            {
                continue;
            }
            int max_time = 0;
            for (int i = 0; i < n; ++i)
            {
                if ((1 << i) & mask)
                {
                    max_time = max(max_time, time[i]);
                }
            }
            mask_time[mask] = max_time;
        }

        min_heap.push({0.0, 0});
        while (!min_heap.empty())
        {
            auto [cost, state] = min_heap.top();
            min_heap.pop();
            int end_mask = state / mask_base;
            if (end_mask == final_mask)
            {
                return cost;
            }
            if (cost > dist[state])
            {
                continue;
            }
            int stage = (state % mask_base) / stage_base;
            int boat_pos = (state % stage_base);
            if (boat_pos == 1)
            {
                for (int i = 0; i < time.size(); ++i)
                {
                    // people not in end
                    if (!((1 << i) & end_mask))
                    {
                        continue;
                    }
                    double time_cost = time[i] * mul[stage];
                    double next_cost = cost + time_cost;
                    int next_end_mask = end_mask ^ (1 << i);
                    int next_stage =
                        (stage + static_cast<int>(floor(time_cost))) % m;
                    int next_state =
                        next_end_mask * mask_base + next_stage * stage_base;
                    if (dist[next_state] > next_cost)
                    {
                        dist[next_state] = next_cost;
                        min_heap.emplace(next_cost, next_state);
                    }
                }
            }
            else
            {
                int remaining = final_mask ^ end_mask;
                for (size_t mask = remaining; mask > 0;
                     mask = (mask - 1) & remaining)
                {
                    if (popcount(mask) > k)
                    {
                        continue;
                    }
                    double time_cost = mask_time[mask] * mul[stage];
                    int next_stage =
                        (stage + static_cast<int>(floor(time_cost))) % m;
                    int next_end_mask = mask | end_mask;
                    double next_cost = cost + time_cost;
                    int next_state =
                        next_end_mask * mask_base + next_stage * stage_base + 1;
                    if (dist[next_state] > next_cost)
                    {
                        dist[next_state] = next_cost;
                        min_heap.emplace(next_cost, next_state);
                    }
                }
            }
        }
        return -1;
    }
};
