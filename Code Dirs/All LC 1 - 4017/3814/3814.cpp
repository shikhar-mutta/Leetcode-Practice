// Link: https://leetcode.com/problems/maximum-capacity-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n) + O(n) + O(n) = O(nlogn)
// SC: O(n) + O(n) = O(n)
// Approach:
// 1. We can use a lookup array to store the maximum capacity for each cost less than the budget.
// 2. We can iterate through the costs and for each cost, we can check if it is less than or equal to half of the budget. If it is, we can update the result with the sum of the current capacity and the maximum capacity so far.
// 3. We can then iterate through the costs again and for each cost that is greater than half of the budget but less than the budget, we can update the result with the sum of the current capacity and the maximum capacity for the remaining budget.
// 4. Finally, we return the result.
class Solution
{
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget)
    {
        int n = costs.size();
        int mid = (budget - 1) / 2;
        if (n == 0)
            return 0;

        int result = 0;
        int maxCapacitySoFar = 0;
        for (int i = 0; i < n; ++i)
        {
            if (costs[i] > mid)
            {
                continue;
            }

            // Result = sum of highest capacities with both pairs <= mid
            result = max(result, capacity[i] + maxCapacitySoFar);
            maxCapacitySoFar = max(maxCapacitySoFar, capacity[i]);
        }

        vector<int> lookup(budget, 0);
        for (int i = 0; i < n; ++i)
        {
            if (costs[i] >= budget)
                continue;

            lookup[costs[i]] = max(lookup[costs[i]], capacity[i]);
        }

        for (int i = 0; i + 1 <= mid; ++i)
        {
            lookup[i + 1] = max(lookup[i], lookup[i + 1]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (costs[i] > mid && costs[i] < budget)
            {
                result =
                    max(result, capacity[i] + lookup[budget - costs[i] - 1]);
            }
        }

        return result;
    }
};

class Solution3
{
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget)
    {
        int total = capacity.size();
        vector<pair<int, int>> machines;
        int maxCapacity = 0;

        for (int idx = 0; idx < total; idx++)
        {
            // no point in adding if it's greater than budget
            if (costs[idx] >= budget)
                continue;

            // consider taking only that machine if <=budget
            maxCapacity = max(maxCapacity, capacity[idx]);

            machines.push_back(make_pair(costs[idx], capacity[idx]));
        }

        // now we do for two machines!
        sort(machines.begin(), machines.end());

        // it always means all elements are good to take before this index
        //  [as machines size keeps on increasing, we want to stop decreasing
        //  size of the other machine]

        // let's store it now also in a priority queue (but order it by max
        // capacity) our job is to start using our array start from highest cost
        // : all all costs lower than this to the priority queue
        //  (by costs lower we mean,all that have cost <= (budget -
        //  current_highest_cost)) We take highest capapcity from priority queue
        //  and use it! (don't remove for now)
        // after processing this cost, we go to a lower cost
        //  we check if we can add more items will lower cost
        //  we also check in this case, if priority queue needs elements to be
        //  removed ?? (because it might have older ones (like our own one at
        //  the top!!))

        // let's try to code this!!
        int endIdx = 0;

        priority_queue<pair<int, int>> capacityQ;

        // for (auto &machine: machines) cout<<machine.first<<"
        // "<<machine.second<<endl;

        for (int idx = machines.size() - 1; idx >= 0; idx--)
        {
            // start from this machine and see if you can use it
            // see how many can you use and keep moving towards 0
            while (endIdx < idx)
            {
                if (budget - machines[idx].first > machines[endIdx].first)
                {
                    capacityQ.push(make_pair(machines[endIdx].second, endIdx));
                    endIdx++;
                }
                else
                {
                    break;
                }
            }

            // todo: optimization --> break off if endIdx is equal to your idx
            // take topmost item from the queue, remove if idx is same as you or
            // greater than you
            while (!capacityQ.empty())
            {
                if (capacityQ.top().second >= idx)
                    capacityQ.pop();
                else
                {
                    maxCapacity = max(maxCapacity, capacityQ.top().first +
                                                       machines[idx].second);
                    break;
                }
            }

            // if (endIdx > idx) break;
        }

        return maxCapacity;
    }
};