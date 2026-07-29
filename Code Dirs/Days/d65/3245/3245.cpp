// Link: https://leetcode.com/problems/alternating-groups-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+Q) log N), SC: O(N)
// Approach: track "breakpoints" (positions where colors[i]==colors[i-1] circularly), which split
// the circle into alternating segments. A Fenwick tree indexed by segment length maintains count
// and sum of lengths, so a size-m query answers via sum(len-m+1) over lengths>=m in O(log N)
// (special-cased when there are no breakpoints — the whole circle is one alternating cycle, and
// every rotation is a valid start). A color update touches at most two breakpoint positions,
// each causing an O(1) segment split or merge (found via set neighbors), updated in the Fenwick tree.
class Solution {
public:
    int n;
    vector<int> colors;
    set<int> breaks;
    vector<long long> bitCount, bitSum;

    void bitAdd(int len, long long deltaCount, long long deltaSum) {
        for (int i = len; i <= n; i += i & (-i)) { bitCount[i] += deltaCount; bitSum[i] += deltaSum; }
    }
    pair<long long,long long> bitQuery(int len) { // sum for [1..len]
        long long c = 0, s = 0;
        for (int i = len; i > 0; i -= i & (-i)) { c += bitCount[i]; s += bitSum[i]; }
        return {c, s};
    }
    pair<long long,long long> rangeQuery(int lo, int hi) { // inclusive, counts/sum of lengths in [lo,hi]
        if (lo > hi) return {0, 0};
        auto a = bitQuery(hi);
        auto b = bitQuery(lo-1);
        return {a.first - b.first, a.second - b.second};
    }

    void addSegment(int len) { if (len > 0) bitAdd(len, 1, len); }
    void removeSegment(int len) { if (len > 0) bitAdd(len, -1, -len); }

    bool isBreak(int p) { return colors[p] == colors[(p-1+n)%n]; }

    int segLenFrom(int a) { // length of segment starting exactly at breakpoint a
        auto it = breaks.find(a);
        auto nxt = next(it);
        int b = (nxt == breaks.end()) ? *breaks.begin() : *nxt;
        int len = (b - a + n) % n;
        return len == 0 ? n : len;
    }

    void handlePosition(int p) {
        bool newB = isBreak(p);
        bool oldB = breaks.count(p) > 0;
        if (newB == oldB) return;

        if (newB && !oldB) {
            if (breaks.empty()) {
                breaks.insert(p);
                addSegment(n);
                return;
            }
            // find segment containing p: prev breakpoint (circular) is the segment start
            auto it = breaks.upper_bound(p);
            int startBp = (it == breaks.begin()) ? *breaks.rbegin() : *prev(it);
            int oldLen = segLenFrom(startBp);
            removeSegment(oldLen);
            breaks.insert(p);
            int len1 = (p - startBp + n) % n;
            int len2 = oldLen - len1;
            addSegment(len1);
            addSegment(len2);
        } else {
            // remove breakpoint p, merging its two neighboring segments
            if (breaks.size() == 1) {
                removeSegment(n);
                breaks.erase(p);
                return; // whole circle now one alternating cycle, no explicit segment stored
            }
            auto it = breaks.find(p);
            auto pr = (it == breaks.begin()) ? prev(breaks.end()) : prev(it);
            int startBp = *pr;
            int len1 = segLenFrom(startBp);
            int len2 = segLenFrom(p);
            removeSegment(len1);
            removeSegment(len2);
            breaks.erase(it);
            addSegment(len1 + len2);
        }
    }

    vector<int> numberOfAlternatingGroups(vector<int>& colors_, vector<vector<int>>& queries) {
        colors = colors_;
        n = colors.size();
        bitCount.assign(n+1, 0);
        bitSum.assign(n+1, 0);

        for (int i = 0; i < n; i++) if (isBreak(i)) breaks.insert(i);
        if (!breaks.empty()) {
            for (int b : breaks) addSegment(segLenFrom(b));
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int m = q[1];
                if (breaks.empty()) {
                    ans.push_back(m <= n ? n : 0);
                } else {
                    auto [cnt, sum] = rangeQuery(m, n);
                    ans.push_back((int)(sum - cnt * (m - 1)));
                }
            } else {
                int idx = q[1], c = q[2];
                colors[idx] = c;
                handlePosition(idx);
                handlePosition((idx+1) % n);
            }
        }
        return ans;
    }
};
