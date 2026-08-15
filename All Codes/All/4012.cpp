// Link: https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + tasks[i];
        long long total = prefix[n];

        vector<int> ans;
        ans.reserve(shifts.size());
        long long consumed = 0;
        for (int s : shifts) {
            consumed += s;
            if (consumed >= total) {
                ans.push_back(0);
                consumed = 0;
            } else {
                int taskIdx = (int)(upper_bound(prefix.begin(), prefix.end(), consumed) - prefix.begin()) - 1;
                ans.push_back(n - taskIdx);
            }
        }
        return ans;
    }
};
