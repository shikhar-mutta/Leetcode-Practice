// Link: https://leetcode.com/problems/process-tasks-using-servers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeQ; // {weight, idx}
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> busyQ; // {freeTime, weight, idx}

        for (int i = 0; i < n; i++) freeQ.push({servers[i], i});

        vector<int> res(m);
        for (int t = 0; t < m; t++) {
            while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {
                auto [ft, w, idx] = busyQ.top(); busyQ.pop();
                freeQ.push({w, idx});
            }
            if (freeQ.empty()) {
                auto [ft, w, idx] = busyQ.top(); busyQ.pop();
                res[t] = idx;
                busyQ.push({ft + tasks[t], w, idx});
            } else {
                auto [w, idx] = freeQ.top(); freeQ.pop();
                res[t] = idx;
                busyQ.push({(long long)t + tasks[t], w, idx});
            }
        }
        return res;
    }
};
