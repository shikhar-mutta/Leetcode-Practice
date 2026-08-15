// Link: https://leetcode.com/problems/employee-importance/description/

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// TC: O(n) SC: O(n)
// Approach: build id->Employee map, then DFS from the target id summing importance across subordinates.
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> byId;
        for (auto* e : employees) byId[e->id] = e;
        return dfs(byId, id);
    }
    int dfs(unordered_map<int, Employee*>& byId, int id) {
        Employee* e = byId[id];
        int total = e->importance;
        for (int sub : e->subordinates) total += dfs(byId, sub);
        return total;
    }
};
