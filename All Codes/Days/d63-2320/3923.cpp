// Link: https://leetcode.com/problems/minimum-generations-to-target-point/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(G * S^2) where S is the bounded set of reachable points SC: O(S)
// Approach: coordinates stay within a small bounded range, so simulate
// generation by generation: at each step, compute midpoints of every
// pair from the cumulative point set so far, add any brand-new ones,
// and check if the target appeared. Stop at a fixpoint (no new points)
// if the target is never produced.
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        using P = array<int, 3>;
        set<P> cur;
        for (auto& p : points) cur.insert({p[0], p[1], p[2]});

        P tgt = {target[0], target[1], target[2]};
        if (cur.count(tgt)) return 0;

        int gen = 0;
        while (true) {
            gen++;
            vector<P> all(cur.begin(), cur.end());
            set<P> newPts;
            for (int i = 0; i < (int)all.size(); i++) {
                for (int j = i + 1; j < (int)all.size(); j++) {
                    P c = {
                        (all[i][0] + all[j][0]) / 2,
                        (all[i][1] + all[j][1]) / 2,
                        (all[i][2] + all[j][2]) / 2
                    };
                    if (!cur.count(c)) newPts.insert(c);
                }
            }
            if (newPts.empty()) return -1;
            if (newPts.count(tgt)) return gen;
            for (auto& p : newPts) cur.insert(p);
        }
    }
};
