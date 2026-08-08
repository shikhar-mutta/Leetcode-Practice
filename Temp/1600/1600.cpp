// Link: https://leetcode.com/problems/throne-inheritance/description/

#include <bits/stdc++.h>
using namespace std;

class ThroneInheritance {
public:
    string king;
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;

    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    void dfs(const string& name, vector<string>& order) {
        if (!dead.count(name)) order.push_back(name);
        for (auto& child : children[name]) dfs(child, order);
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};
