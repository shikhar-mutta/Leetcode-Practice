// Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^r * n) SC: O(n)
// Approach: We can use backtracking to solve this problem. We can keep track of the
class Solution
{
public:
    int maxReq = 0;

    void backtrack(int idx, int count, vector<vector<int>> &reqs,
                   vector<int> &degree)
    {
        // Pruning: If we take all remaining requests and still can't beat
        // maxReq, abort.
        if (count + (reqs.size() - idx) <= maxReq)
            return;

        // Base case: All requests processed
        if (idx == reqs.size())
        {
            for (int d : degree)
            {
                if (d != 0)
                    return; // Invalid configuration
            }
            maxReq = max(maxReq, count);
            return;
        }

        // Branch 1: INCLUDE reqs[idx] (Try this first to maximize 'count' early
        // for better pruning)
        int u = reqs[idx][0];
        int v = reqs[idx][1];
        degree[u]--;
        degree[v]++;

        backtrack(idx + 1, count + 1, reqs, degree);

        // Backtrack (undo state changes)
        degree[u]++;
        degree[v]--;

        // Branch 2: EXCLUDE reqs[idx]
        backtrack(idx + 1, count, reqs, degree);
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int selfLoops = 0;
        vector<vector<int>> filteredReqs;
        filteredReqs.reserve(requests.size());

        // Step 1: Strip self-loops
        for (const auto &req : requests)
        {
            if (req[0] == req[1])
            {
                selfLoops++;
            }
            else
            {
                filteredReqs.push_back(req);
            }
        }

        vector<int> degree(n, 0);
        maxReq = 0;

        // Step 2 & 3: Backtrack with pruning and in-place state
        backtrack(0, 0, filteredReqs, degree);

        return maxReq + selfLoops;
    }
};