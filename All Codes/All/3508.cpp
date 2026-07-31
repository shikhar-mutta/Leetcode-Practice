// Link: https://leetcode.com/problems/implement-router/description/

#include <bits/stdc++.h>
using namespace std;

class Router {
    int memoryLimit;
    deque<tuple<int,int,int>> packets;
    set<tuple<int,int,int>> seen;
    unordered_map<int, deque<int>> destTimestamps;
public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        auto key = make_tuple(source, destination, timestamp);
        if (seen.count(key)) return false;
        if ((int)packets.size() >= memoryLimit) {
            auto old = packets.front(); packets.pop_front();
            seen.erase(old);
            destTimestamps[get<1>(old)].pop_front();
        }
        packets.push_back(key);
        seen.insert(key);
        destTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        auto p = packets.front(); packets.pop_front();
        seen.erase(p);
        destTimestamps[get<1>(p)].pop_front();
        return {get<0>(p), get<1>(p), get<2>(p)};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& dq = destTimestamps[destination];
        auto lo = lower_bound(dq.begin(), dq.end(), startTime);
        auto hi = upper_bound(dq.begin(), dq.end(), endTime);
        return (int)(hi - lo);
    }
};
