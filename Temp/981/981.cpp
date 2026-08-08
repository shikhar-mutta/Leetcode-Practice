// Link: https://leetcode.com/problems/time-based-key-value-store/description/

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int,string>>> store;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        auto& vec = it->second;
        int lo = 0, hi = vec.size() - 1, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (vec[mid].first <= timestamp) { res = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return res == -1 ? "" : vec[res].second;
    }
};
