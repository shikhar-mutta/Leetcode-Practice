// Link: https://leetcode.com/problems/closest-room/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n + q) log n)  SC: O(n)
// Approach: sort rooms and queries by size descending; process queries in that
// order, adding rooms with sufficient size into an ordered set of ids as we go,
// then binary-search the set for the closest id to preferred using neighbors.
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
        int q = queries.size();
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return queries[a][1] > queries[b][1]; });

        set<int> ids;
        vector<int> ans(q, -1);
        int ri = 0;
        for (int qi : idx) {
            int preferred = queries[qi][0], minSize = queries[qi][1];
            while (ri < (int)rooms.size() && rooms[ri][1] >= minSize) {
                ids.insert(rooms[ri][0]);
                ri++;
            }
            if (ids.empty()) continue;
            auto it = ids.lower_bound(preferred);
            int best = -1, bestDiff = INT_MAX;
            if (it != ids.end()) {
                int diff = abs(*it - preferred);
                if (diff < bestDiff) { bestDiff = diff; best = *it; }
            }
            if (it != ids.begin()) {
                auto pit = prev(it);
                int diff = abs(*pit - preferred);
                if (diff < bestDiff || (diff == bestDiff && *pit < best)) { bestDiff = diff; best = *pit; }
            }
            ans[qi] = best;
        }
        return ans;
    }
};
