// Link: https://leetcode.com/problems/design-ride-sharing-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per op SC: O(n)
// Approach: FIFO queues for waiting riders and drivers. Cancelled riders
// are marked in a set rather than removed from the queue (O(1) cancel);
// matchDriverWithRider pops drivers normally, but skips (discards)
// riders at the queue front that were cancelled before returning the
// first live one.
class RideSharingSystem {
    queue<int> riders, drivers;
    unordered_set<int> cancelled;
public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    void cancelRider(int riderId) {
        cancelled.insert(riderId);
    }

    vector<int> matchDriverWithRider() {
        while (!riders.empty() && cancelled.count(riders.front())) {
            cancelled.erase(riders.front());
            riders.pop();
        }
        if (drivers.empty() || riders.empty()) return {-1, -1};
        int d = drivers.front(); drivers.pop();
        int r = riders.front(); riders.pop();
        return {d, r};
    }
};
