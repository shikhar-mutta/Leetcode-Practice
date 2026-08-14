// Link: https://leetcode.com/problems/minimum-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> dist(n, -1);
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        set<int> evens, odds;
        for (int i = 0; i < n; i++) {
            if (bannedSet.count(i) || i == p) continue;
            if (i % 2 == 0) evens.insert(i);
            else odds.insert(i);
        }

        dist[p] = 0;
        queue<int> q;
        q.push(p);

        while (!q.empty()) {
            int pos = q.front(); q.pop();
            int lo = max(0, pos - k + 1);
            int hi = min(n - k, pos);
            if (lo > hi) continue;

            int rangeLo = 2 * lo + k - 1 - pos;
            int rangeHi = 2 * hi + k - 1 - pos;

            set<int> &avail = (rangeLo % 2 == 0) ? evens : odds;
            auto it = avail.lower_bound(rangeLo);
            while (it != avail.end() && *it <= rangeHi) {
                int nxt = *it;
                dist[nxt] = dist[pos] + 1;
                q.push(nxt);
                it = avail.erase(it);
            }
        }

        return dist;
    }
};
