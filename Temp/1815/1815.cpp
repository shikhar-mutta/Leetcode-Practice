// Link: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int batchSize_;
    map<pair<vector<int>,int>, int> memo;

    int dfs(vector<int> counts, int rem) {
        auto key = make_pair(counts, rem);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int best = 0;
        for (int r = 1; r < batchSize_; r++) {
            if (counts[r] == 0) continue;
            counts[r]--;
            int happy = (rem == 0) ? 1 : 0;
            int val = happy + dfs(counts, (rem + r) % batchSize_);
            best = max(best, val);
            counts[r]++;
        }
        memo[key] = best;
        return best;
    }

    int maxHappyGroups(int batchSize, vector<int>& groups) {
        batchSize_ = batchSize;
        vector<int> cnt(batchSize, 0);
        for (int g : groups) cnt[g % batchSize]++;
        int ans = cnt[0];
        cnt[0] = 0;
        return ans + dfs(cnt, 0);
    }
};
