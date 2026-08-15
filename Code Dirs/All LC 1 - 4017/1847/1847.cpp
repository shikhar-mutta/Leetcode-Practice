// Link: https://leetcode.com/problems/closest-room/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][1] > queries[b][1];
        });

        set<int> ids;
        vector<int> res(m, -1);
        int i = 0;
        for (int qi : idx) {
            int preferredId = queries[qi][0], minSize = queries[qi][1];
            while (i < (int)rooms.size() && rooms[i][1] >= minSize) {
                ids.insert(rooms[i][0]);
                i++;
            }
            if (ids.empty()) continue;
            auto it = ids.lower_bound(preferredId);
            int best = -1, bestDiff = INT_MAX;
            if (it != ids.end()) {
                best = *it;
                bestDiff = abs(*it - preferredId);
            }
            if (it != ids.begin()) {
                auto it2 = prev(it);
                int diff = abs(*it2 - preferredId);
                if (diff < bestDiff || (diff == bestDiff && *it2 < best)) {
                    best = *it2;
                }
            }
            res[qi] = best;
        }
        return res;
    }
};
