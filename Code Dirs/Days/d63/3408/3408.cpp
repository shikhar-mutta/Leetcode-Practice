// Link: https://leetcode.com/problems/design-task-manager/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
// Approach: keep taskId -> (userId, priority) map plus a sorted set of
// (priority, taskId) pairs. edit/rmv erase the old (priority, taskId)
// entry before updating; execTop pops the max (priority, taskId) entry.
class TaskManager {
    unordered_map<int, pair<int,int>> taskInfo; // taskId -> (userId, priority)
    set<pair<int,int>> order; // (priority, taskId)
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) add(t[0], t[1], t[2]);
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        order.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto& info = taskInfo[taskId];
        order.erase({info.second, taskId});
        info.second = newPriority;
        order.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        auto info = taskInfo[taskId];
        order.erase({info.second, taskId});
        taskInfo.erase(taskId);
    }

    int execTop() {
        if (order.empty()) return -1;
        auto [priority, taskId] = *order.rbegin();
        int userId = taskInfo[taskId].first;
        order.erase({priority, taskId});
        taskInfo.erase(taskId);
        return userId;
    }
};
