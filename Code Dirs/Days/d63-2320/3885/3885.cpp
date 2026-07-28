// Link: https://leetcode.com/problems/design-event-manager/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
//  Approach: keep eventId->priority map plus an ordered set of
//  (priority, eventId) pairs. pollHighest takes the max pair (ties broken
//  by smaller eventId since we negate priority for max-as-min ordering);
//  updatePriority removes the old pair and reinserts with the new value.
class EventManager
{
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> eventMap;
    EventManager(vector<vector<int>> &events)
    {
        for (auto &event : events)
        {
            pq.emplace(event[1], -event[0]);
            eventMap[event[0]] = event[1];
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        eventMap[eventId] = newPriority;
        pq.emplace(newPriority, -eventId);
    }

    int pollHighest()
    {
        while (!pq.empty())
        {
            auto [priority, eventId] = pq.top();
            eventId = -eventId;
            pq.pop();
            if (eventMap[eventId] == priority)
            {
                eventMap[eventId] = -1;
                return eventId;
            }
        }
        return -1;
    }
};
