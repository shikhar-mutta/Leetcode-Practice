// Link: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: exponential worst case, bounded by memoized search over remainder-count states (batchSize<=9)
// SC: memo map size bounded by distinct states
// Approach: bucket groups by remainder mod batchSize; remainder 0 always forms a
// happy group. Greedily pair up complementary remainders (r, batchSize-r) first
// since that's always optimal. For the leftover counts, do a memoized DFS trying
// each remainder type next, tracking current running remainder to detect fresh starts.
class Solution {
    unordered_map<string,int> memo;
    int batchSize;

    string encode(vector<int>& cnt, int rem) {
        string s;
        for (int c : cnt) s += char('0' + c);
        s += '|';
        s += to_string(rem);
        return s;
    }

    int dfs(vector<int>& cnt, int curRemainder) {
        bool allZero = true;
        for (int c : cnt) if (c > 0) { allZero = false; break; }
        if (allZero) return 0;
        string key = encode(cnt, curRemainder);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int best = 0;
        for (int i = 1; i < batchSize; i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            int gain = (curRemainder == 0) ? 1 : 0;
            int res = gain + dfs(cnt, (curRemainder + i) % batchSize);
            cnt[i]++;
            best = max(best, res);
        }
        memo[key] = best;
        return best;
    }
public:
    int maxHappyGroups(int batchSize_, vector<int>& groups) {
        batchSize = batchSize_;
        vector<int> cnt(batchSize, 0);
        int ans = 0;
        for (int g : groups) {
            int r = g % batchSize;
            if (r == 0) ans++;
            else cnt[r]++;
        }
        for (int r = 1; r < batchSize; r++) {
            int comp = batchSize - r;
            if (r < comp) {
                int p = min(cnt[r], cnt[comp]);
                ans += p;
                cnt[r] -= p;
                cnt[comp] -= p;
            } else if (r == comp) {
                ans += cnt[r] / 2;
                cnt[r] %= 2;
            }
        }
        ans += dfs(cnt, 0);
        return ans;
    }
};
