// Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int best;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        vector<int> load(k, 0);
        best = accumulate(jobs.begin(), jobs.end(), 0);
        dfs(jobs, 0, load, 0);
        return best;
    }

    void dfs(vector<int>& jobs, int idx, vector<int>& load, int curMax) {
        if (idx == (int)jobs.size()) {
            best = min(best, curMax);
            return;
        }
        if (curMax >= best) return;
        unordered_set<int> tried;
        for (int i = 0; i < (int)load.size(); i++) {
            if (tried.count(load[i])) continue;
            tried.insert(load[i]);
            load[i] += jobs[idx];
            dfs(jobs, idx + 1, load, max(curMax, load[i]));
            load[i] -= jobs[idx];
        }
    }
};
