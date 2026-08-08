// Link: https://leetcode.com/problems/snapshot-array/description/

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
    vector<vector<pair<int,int>>> history;
    int snapId = 0;
public:
    SnapshotArray(int length) : history(length) {
        for (auto& h : history) h.push_back({0, 0});
    }

    void set(int index, int val) {
        history[index].push_back({snapId, val});
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto& h = history[index];
        int lo = 0, hi = h.size() - 1, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (h[mid].first <= snap_id) { res = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return h[res].second;
    }
};
