// Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n * log n)  SC: O(n)
// Approach: binary search on the number of tasks k assignable. Feasibility
// check: take the k weakest tasks and k strongest workers; greedily match
// from the strongest task down — if the strongest available worker can do it
// unaided, use them; otherwise use a pill on the weakest worker who can do it
// (found via multiset lower_bound), consuming a pill. Feasible iff pills
// suffice.
class Solution {
    bool feasible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        multiset<int> ws(workers.end() - k, workers.end());
        int pillsLeft = pills;
        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];
            auto it = prev(ws.end());
            if (*it >= task) {
                ws.erase(it);
            } else {
                auto need = ws.lower_bound(task - strength);
                if (need == ws.end() || pillsLeft == 0) return false;
                pillsLeft--;
                ws.erase(need);
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int lo = 0, hi = min(tasks.size(), workers.size());
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (feasible(tasks, workers, pills, strength, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
