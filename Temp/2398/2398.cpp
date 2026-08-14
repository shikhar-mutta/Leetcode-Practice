// Link: https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        deque<int> dq;
        long long sumCost = 0;
        int left = 0, best = 0;
        for (int right = 0; right < n; right++) {
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) dq.pop_back();
            dq.push_back(right);
            sumCost += runningCosts[right];

            while (!dq.empty() && chargeTimes[dq.front()] + (long long)(right - left + 1) * sumCost > budget) {
                if (dq.front() == left) dq.pop_front();
                sumCost -= runningCosts[left];
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
