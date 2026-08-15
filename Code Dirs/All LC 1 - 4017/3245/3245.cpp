// Link: https://leetcode.com/problems/alternating-groups-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Fenwick {
        vector<long long> tree;
        int n;
        Fenwick(int n) : tree(n + 1, 0), n(n) {}
        void update(int i, long long delta) {
            for (; i <= n; i += i & (-i)) tree[i] += delta;
        }
        long long query(int i) { // prefix sum [1..i]
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += tree[i];
            return s;
        }
        long long rangeSum(int l, int r) {
            if (l > r) return 0;
            return query(r) - query(l - 1);
        }
    };

    int n;
    set<int> breakSet;
    Fenwick* cntBIT;
    Fenwick* sumBIT;

    void addGap(int len) {
        if (len <= 0) return;
        cntBIT->update(len, 1);
        sumBIT->update(len, len);
    }
    void removeGap(int len) {
        if (len <= 0) return;
        cntBIT->update(len, -1);
        sumBIT->update(len, -len);
    }

    void insertBreak(int e) {
        if (breakSet.empty()) {
            addGap(n);
            breakSet.insert(e);
            return;
        }
        if (breakSet.size() == 1) {
            int only = *breakSet.begin();
            removeGap(n);
            int gap1 = (e - only + n) % n;
            int gap2 = (only - e + n) % n;
            addGap(gap1); addGap(gap2);
            breakSet.insert(e);
            return;
        }
        auto itNext = breakSet.upper_bound(e);
        int nextVal, prevVal;
        if (itNext == breakSet.end()) {
            nextVal = *breakSet.begin();
            prevVal = *breakSet.rbegin();
        } else if (itNext == breakSet.begin()) {
            nextVal = *itNext;
            prevVal = *breakSet.rbegin();
        } else {
            nextVal = *itNext;
            prevVal = *prev(itNext);
        }
        int oldGap = (nextVal - prevVal + n) % n;
        removeGap(oldGap);
        int gap1 = (e - prevVal + n) % n;
        int gap2 = (nextVal - e + n) % n;
        addGap(gap1); addGap(gap2);
        breakSet.insert(e);
    }

    void removeBreak(int e) {
        if (breakSet.size() == 1) {
            removeGap(n);
            breakSet.erase(e);
            return;
        }
        if (breakSet.size() == 2) {
            int other = (*breakSet.begin() == e) ? *breakSet.rbegin() : *breakSet.begin();
            int gapA = (other - e + n) % n;
            int gapB = (e - other + n) % n;
            removeGap(gapA); removeGap(gapB);
            addGap(n);
            breakSet.erase(e);
            return;
        }
        auto it = breakSet.find(e);
        auto itPrev = (it == breakSet.begin()) ? prev(breakSet.end()) : prev(it);
        auto itNext = next(it);
        if (itNext == breakSet.end()) itNext = breakSet.begin();
        int prevVal = *itPrev, nextVal = *itNext;
        int gap1 = (e - prevVal + n) % n;
        int gap2 = (nextVal - e + n) % n;
        removeGap(gap1); removeGap(gap2);
        int merged = (nextVal - prevVal + n) % n;
        addGap(merged);
        breakSet.erase(e);
    }

    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        n = colors.size();
        cntBIT = new Fenwick(n);
        sumBIT = new Fenwick(n);
        breakSet.clear();

        for (int i = 0; i < n; i++) {
            if (colors[i] == colors[(i + 1) % n]) breakSet.insert(i);
        }
        if (!breakSet.empty()) {
            vector<int> breaks(breakSet.begin(), breakSet.end());
            int k = breaks.size();
            for (int i = 0; i < k; i++) {
                int cur = breaks[i], nxt = breaks[(i + 1) % k];
                int gap = (nxt - cur + n) % n;
                if (gap == 0) gap = n; // k==1 case
                addGap(gap);
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int s = q[1];
                if (breakSet.empty()) {
                    res.push_back(n);
                } else {
                    long long countGE = cntBIT->rangeSum(s, n);
                    long long sumGE = sumBIT->rangeSum(s, n);
                    long long ans = sumGE - (long long)(s - 1) * countGE;
                    res.push_back((int)ans);
                }
            } else {
                int idx = q[1], newColor = q[2];
                if (colors[idx] == newColor) continue;
                int leftE = (idx - 1 + n) % n, rightE = idx;
                bool oldLeft = breakSet.count(leftE) > 0;
                bool oldRight = breakSet.count(rightE) > 0;
                colors[idx] = newColor;
                bool newLeft = (colors[leftE] == colors[(leftE + 1) % n]);
                bool newRight = (colors[rightE] == colors[(rightE + 1) % n]);
                if (oldLeft != newLeft) {
                    if (newLeft) insertBreak(leftE); else removeBreak(leftE);
                }
                if (oldRight != newRight) {
                    if (newRight) insertBreak(rightE); else removeBreak(rightE);
                }
            }
        }

        delete cntBIT;
        delete sumBIT;
        return res;
    }
};
