// Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool feasible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        // k easiest tasks, k strongest workers
        multiset<int> avail(workers.end() - k, workers.end());
        int usedPills = 0;
        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];
            auto it = prev(avail.end());
            if (*it >= task) {
                avail.erase(it);
            } else {
                auto it2 = avail.lower_bound(task - strength);
                if (it2 == avail.end()) return false;
                avail.erase(it2);
                usedPills++;
                if (usedPills > pills) return false;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int lo = 0, hi = min(tasks.size(), workers.size());
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (feasible(tasks, workers, pills, strength, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
