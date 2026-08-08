// Link: https://leetcode.com/problems/single-threaded-cpu/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0];
        });

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq; // {procTime, origIdx}
        vector<int> res;
        long long time = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty() && time < tasks[idx[i]][0]) time = tasks[idx[i]][0];
            while (i < n && tasks[idx[i]][0] <= time) {
                pq.push({tasks[idx[i]][1], idx[i]});
                i++;
            }
            auto [proc, taskIdx] = pq.top(); pq.pop();
            time += proc;
            res.push_back(taskIdx);
        }
        return res;
    }
};
