// Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> workers;
    int best;

    bool dfs(vector<int>& jobs, int idx, int k) {
        if (idx == (int)jobs.size()) {
            int mx = *max_element(workers.begin(), workers.end());
            best = min(best, mx);
            return true;
        }
        unordered_set<int> tried;
        for (int i = 0; i < k; i++) {
            if (tried.count(workers[i])) continue;
            if (workers[i] + jobs[idx] >= best) continue;
            tried.insert(workers[i]);
            workers[i] += jobs[idx];
            dfs(jobs, idx + 1, k);
            workers[i] -= jobs[idx];
        }
        return true;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        workers.assign(k, 0);
        best = INT_MAX;
        dfs(jobs, 0, k);
        return best;
    }
};
