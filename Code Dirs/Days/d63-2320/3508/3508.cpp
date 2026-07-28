// Link: https://leetcode.com/problems/implement-router/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: Use a queue to maintain the order of packets and a hash set to check for duplicates. Use a hash map to maintain a time logger for each destination, which keeps track of the timestamps of packets sent to that destination. When adding a packet, check if it already exists in the hash set. If it does not, add it to the queue and the hash set, and update the time logger for the destination. When forwarding a packet, pop it from the queue and remove it from the hash set, and update the time logger for the destination. To get the count of packets sent to a destination within a time range, use binary search on the timestamps in the time logger.
class Router
{
    struct Packet
    {
        struct Hasher
        {
            size_t operator()(const Packet &p) const
            {
                size_t h1 = hash<int>{}(p.source);
                size_t h2 = hash<int>{}(p.destination);
                size_t h3 = hash<int>{}(p.timestamp);

                return (h1 << 2) ^ (h2 << 1) ^ h3;
            }
        };

        int source;
        int destination;
        int timestamp;

        bool operator==(const Packet &p) const
        {
            return make_tuple(source, destination, timestamp) ==
                   make_tuple(p.source, p.destination, p.timestamp);
        }
    };

    struct TimeLogger
    {
        int timeIdx;
        vector<int> timestamps;

        TimeLogger() : timeIdx{0}, timestamps{} {}

        int getCount(int startTime, int endTime)
        {
            int idxStart = lower_bound(timestamps.begin() + timeIdx,
                                       timestamps.end(), startTime) -
                           timestamps.begin();
            int idxEnd = upper_bound(timestamps.begin() + timeIdx,
                                     timestamps.end(), endTime) -
                         timestamps.begin();
            return idxEnd - idxStart;
        }

        void addTime(int tm) { timestamps.push_back(tm); }

        void shiftTime() { timeIdx++; }
    };

    int memoryLimit;
    unordered_set<Packet, Packet::Hasher> packets;
    unordered_map<int, TimeLogger> destLoggers;
    queue<Packet> packetQueue;

    Packet popPacket()
    {
        auto packet = packetQueue.front();

        packetQueue.pop();

        packets.erase(packet);

        destLoggers[packet.destination].shiftTime();

        return packet;
    }

    void pushPacket(const Packet &packet)
    {
        while (packetQueue.size() + 1 > memoryLimit)
        {
            popPacket();
        }
        packets.insert(packet);
        packetQueue.push(packet);
        destLoggers[packet.destination].addTime(packet.timestamp);
    }

    static std::vector<int> serialize(const Packet &packet)
    {
        return std::vector<int>{packet.source, packet.destination,
                                packet.timestamp};
    }

public:
    Router(int memoryLimit) : memoryLimit{memoryLimit} {}

    bool addPacket(int source, int destination, int timestamp)
    {
        auto packet = Packet{.source = source,
                             .destination = destination,
                             .timestamp = timestamp};
        if (packets.count(packet))
        {
            return false;
        }
        pushPacket(packet);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetQueue.empty())
        {
            return vector<int>{};
        }
        return serialize(popPacket());
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto &logger = destLoggers[destination];
        return logger.getCount(startTime, endTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */