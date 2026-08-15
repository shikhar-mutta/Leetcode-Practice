// Link: https://leetcode.com/problems/most-profit-assigning-work/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + m log m) SC: O(n)
// Approach: pair up (difficulty, profit) and sort by difficulty; sort workers; sweep workers in increasing ability, advancing a pointer through jobs, tracking the max profit achievable so far.
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {difficulty[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int total = 0, best = 0, i = 0;
        for (int w : worker) {
            while (i < n && jobs[i].first <= w) {
                best = max(best, jobs[i].second);
                i++;
            }
            total += best;
        }
        return total;
    }
};
