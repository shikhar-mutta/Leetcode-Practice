// Link: https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: sliding window with monotonic deque tracking max chargeTime in window; running sum
// of runningCosts; shrink window while maxCharge + windowSize*sumCost > budget.
class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        deque<int> dq;
        long long sumCost = 0;
        int l = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            sumCost += runningCosts[r];
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r])
                dq.pop_back();
            dq.push_back(r);

            while (!dq.empty() && chargeTimes[dq.front()] + (long long)(r - l + 1) * sumCost > budget)
            {
                if (dq.front() == l)
                    dq.pop_front();
                sumCost -= runningCosts[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
