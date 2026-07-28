// Link: https://leetcode.com/problems/design-event-manager/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
// Approach: keep eventId->priority map plus an ordered set of
// (priority, eventId) pairs. pollHighest takes the max pair (ties broken
// by smaller eventId since we negate priority for max-as-min ordering);
// updatePriority removes the old pair and reinserts with the new value.
class EventManager {
    unordered_map<int, int> priority;
    set<pair<int, int>> byPriority; // (priority, eventId)
public:
    EventManager(vector<vector<int>>& events) {
        for (auto& e : events) {
            priority[e[0]] = e[1];
            byPriority.insert({e[1], e[0]});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        byPriority.erase({priority[eventId], eventId});
        priority[eventId] = newPriority;
        byPriority.insert({newPriority, eventId});
    }

    int pollHighest() {
        if (byPriority.empty()) return -1;
        auto it = byPriority.end();
        --it;
        int prio = it->first, id = it->second;
        // among ties for max priority, want smallest eventId
        auto lo = byPriority.lower_bound({prio, INT_MIN});
        id = lo->second;
        priority.erase(id);
        byPriority.erase(lo);
        return id;
    }
};
