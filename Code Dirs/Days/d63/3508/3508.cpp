// Link: https://leetcode.com/problems/implement-router/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(memoryLimit)
// Approach: a FIFO deque of packets (for eviction/forwarding order), a
// set of (source,destination,timestamp) triples for O(1) duplicate
// checks, and per-destination deques of timestamps (kept in chronological
// order, matching insertion order) for binary-search range counting.
class Router {
    int limit;
    deque<array<int,3>> q;
    set<tuple<int,int,int>> seen;
    unordered_map<int, deque<int>> destTimes;
public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        auto key = make_tuple(source, destination, timestamp);
        if (seen.count(key)) return false;
        if ((int)q.size() >= limit) {
            auto old = q.front(); q.pop_front();
            seen.erase(make_tuple(old[0], old[1], old[2]));
            destTimes[old[1]].pop_front();
        }
        q.push_back({source, destination, timestamp});
        seen.insert(key);
        destTimes[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto p = q.front(); q.pop_front();
        seen.erase(make_tuple(p[0], p[1], p[2]));
        destTimes[p[1]].pop_front();
        return {p[0], p[1], p[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& v = destTimes[destination];
        auto lo = lower_bound(v.begin(), v.end(), startTime);
        auto hi = upper_bound(v.begin(), v.end(), endTime);
        return hi - lo;
    }
};
