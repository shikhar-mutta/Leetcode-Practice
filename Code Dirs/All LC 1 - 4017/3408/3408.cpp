// Link: https://leetcode.com/problems/design-task-manager/description/

#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    set<pair<int,int>> pq; // (priority, taskId)
    unordered_map<int, pair<int,int>> info; // taskId -> (userId, priority)

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            info[taskId] = {userId, priority};
            pq.insert({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        info[taskId] = {userId, priority};
        pq.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto& [userId, oldPriority] = info[taskId];
        pq.erase({oldPriority, taskId});
        oldPriority = newPriority;
        pq.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        auto it = info.find(taskId);
        pq.erase({it->second.second, taskId});
        info.erase(it);
    }

    int execTop() {
        if (pq.empty()) return -1;
        auto it = prev(pq.end());
        int taskId = it->second;
        int userId = info[taskId].first;
        pq.erase(it);
        info.erase(taskId);
        return userId;
    }
};
