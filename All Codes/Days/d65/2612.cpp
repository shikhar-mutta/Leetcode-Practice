// Link: https://leetcode.com/problems/minimum-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: from position i, reversing any length-k window containing i sends it to positions
// {2l + k-1-i : l in [max(0,i-k+1), min(i,n-k)]}, an arithmetic sequence with step 2 (fixed
// parity). BFS using two sets (one per parity) of unvisited positions; for each expansion,
// binary-search the reachable range and erase all matches in one sweep.
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> dist(n, -1);
        set<int> avail[2];
        vector<bool> isBanned(n, false);
        for (int b : banned) isBanned[b] = true;
        for (int i = 0; i < n; i++) if (!isBanned[i] && i != p) avail[i % 2].insert(i);

        dist[p] = 0;
        queue<int> q; q.push(p);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            int lmin = max(0, i - k + 1), lmax = min(i, n - k);
            if (lmin > lmax) continue;
            int low = 2*lmin + k - 1 - i, high = 2*lmax + k - 1 - i;
            set<int>& s = avail[low % 2 < 0 ? (low % 2 + 2) % 2 : low % 2];
            auto it = s.lower_bound(low);
            while (it != s.end() && *it <= high) {
                dist[*it] = dist[i] + 1;
                q.push(*it);
                it = s.erase(it);
            }
        }
        return dist;
    }
};
