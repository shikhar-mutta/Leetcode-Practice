// Link: https://leetcode.com/problems/design-log-storage-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) put, O(n) retrieve SC: O(n)
// Approach: store (id, timestamp string) pairs; retrieve() truncates the granularity-relevant prefix of both bounds and each stored timestamp, comparing as strings (fixed-width zero-padded fields make lexicographic == numeric comparison).
class LogSystem {
    vector<pair<int, string>> logs;
    unordered_map<string, int> gran = {
        {"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}
    };
public:
    LogSystem() {}

    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        int len = gran[granularity];
        string s = start.substr(0, len);
        string e = end.substr(0, len);
        vector<int> res;
        for (auto& [id, ts] : logs) {
            string t = ts.substr(0, len);
            if (t >= s && t <= e) res.push_back(id);
        }
        return res;
    }
};
