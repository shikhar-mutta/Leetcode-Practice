// Link: https://leetcode.com/problems/maximum-performance-of-a-team/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
//  Approach: Sort the engineers by efficiency in descending order. Then, iterate through the sorted list and maintain a min-heap of the k highest speeds seen so far. For each engineer, calculate the performance of the team consisting of that engineer and the k-1 engineers with the highest speeds seen so far. Keep track of the maximum performance seen during the iteration and return it at the end.
class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                       int k)
    {
        const long long MOD = 1e9 + 7;
        vector<pair<int, int>> team;
        for (int i = 0; i < n; i++)
        {
            team.push_back({efficiency[i], speed[i]});
        }
        sort(team.begin(), team.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.first > b.first;
             });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long totalSpeed = 0;
        long long maxPerformance = 0;
        for (auto [eff, spd] : team)
        {
            totalSpeed += spd;
            minHeap.push(spd);
            if (minHeap.size() > k)
            {
                totalSpeed -= minHeap.top();
                minHeap.pop();
            }
            long long performance = totalSpeed * eff;
            maxPerformance = max(maxPerformance, totalSpeed * eff);
        }
        return maxPerformance % MOD;
    }
};
