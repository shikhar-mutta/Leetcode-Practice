// Link: https://leetcode.com/problems/design-hit-counter/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized hit, O(1) amortized getHits  SC: O(300)
// Approach: queue of timestamps; on getHits, pop timestamps older than
// (timestamp - 300)
class HitCounter {
    queue<int> hits;

public:
    HitCounter() {}

    void hit(int timestamp) {
        hits.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!hits.empty() && hits.front() <= timestamp - 300) hits.pop();
        return hits.size();
    }
};
