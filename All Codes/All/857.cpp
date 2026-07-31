// Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Sort workers by their wage-to-quality ratio. Use a max-heap to maintain the k workers with the smallest quality sum. For each worker, calculate the total cost if they are included in the group of k workers, and update the minimum cost accordingly.
class Solution
{
public:
    double mincostToHireWorkers(vector<int> &q, vector<int> &w, int k)
    {
        int n = q.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; i++)
        {
            workers[i] = {(double)w[i] / q[i], q[i]};
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = 1e18;

        for (const auto &worker : workers)
        {
            double ratio = worker.first;
            int quality = worker.second;

            qualitySum += quality;
            maxHeap.push(quality);
            if (maxHeap.size() > k)
            {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k)
            {
                minCost = min(minCost, qualitySum * ratio);
            }
        }
        return minCost;
    }
};