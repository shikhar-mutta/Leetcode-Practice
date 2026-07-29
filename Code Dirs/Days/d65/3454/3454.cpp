// Link: https://leetcode.com/problems/separate-squares-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> X;
    vector<int> cnt;
    vector<long long> covLen;
    int m; // number of elementary intervals

    void build(int node, int l, int r) {
        cnt[node] = 0; covLen[node] = 0;
        if (l == r) return;
        int mid = (l + r) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);
    }

    void update(int node, int l, int r, int ql, int qr, int delta) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            cnt[node] += delta;
        } else {
            int mid = (l + r) / 2;
            update(node*2, l, mid, ql, qr, delta);
            update(node*2+1, mid+1, r, ql, qr, delta);
        }
        if (cnt[node] > 0) {
            covLen[node] = X[r+1] - X[l];
        } else if (l == r) {
            covLen[node] = 0;
        } else {
            covLen[node] = covLen[node*2] + covLen[node*2+1];
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        set<long long> xs;
        for (auto& sq : squares) {
            xs.insert(sq[0]);
            xs.insert((long long)sq[0] + sq[2]);
        }
        X.assign(xs.begin(), xs.end());
        m = (int)X.size() - 1;
        if (m <= 0) return 0.0;

        cnt.assign(4*m, 0);
        covLen.assign(4*m, 0);
        build(1, 0, m-1);

        struct Event { long long y; int delta; long long x1, x2; };
        vector<Event> events;
        for (auto& sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y, 1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }
        sort(events.begin(), events.end(), [](const Event& a, const Event& b){ return a.y < b.y; });

        // Pass 1: total area
        long long prevY = events[0].y;
        double totalArea = 0;
        for (size_t i = 0; i < events.size(); ) {
            long long curY = events[i].y;
            totalArea += (double)covLenRoot() * (double)(curY - prevY);
            size_t j = i;
            while (j < events.size() && events[j].y == curY) {
                int xl = lower_bound(X.begin(), X.end(), events[j].x1) - X.begin();
                int xr = lower_bound(X.begin(), X.end(), events[j].x2) - X.begin() - 1;
                update(1, 0, m-1, xl, xr, events[j].delta);
                j++;
            }
            prevY = curY;
            i = j;
        }

        // Pass 2: reset segtree and sweep to find answer
        build(1, 0, m-1);
        double target = totalArea / 2.0;
        double cum = 0;
        prevY = events[0].y;
        double answer = (double)prevY;
        bool found = false;
        for (size_t i = 0; i < events.size() && !found; ) {
            long long curY = events[i].y;
            double curCov = (double)covLenRoot();
            double stripArea = curCov * (double)(curY - prevY);
            if (cum >= target) {
                answer = (double)prevY;
                found = true;
                break;
            }
            if (cum + stripArea >= target) {
                if (curCov > 0) {
                    answer = (double)prevY + (target - cum) / curCov;
                } else {
                    answer = (double)prevY;
                }
                found = true;
                break;
            }
            cum += stripArea;
            size_t j = i;
            while (j < events.size() && events[j].y == curY) {
                int xl = lower_bound(X.begin(), X.end(), events[j].x1) - X.begin();
                int xr = lower_bound(X.begin(), X.end(), events[j].x2) - X.begin() - 1;
                update(1, 0, m-1, xl, xr, events[j].delta);
                j++;
            }
            prevY = curY;
            i = j;
        }
        if (!found) answer = (double)prevY;

        return answer;
    }

    long long covLenRoot() { return covLen.empty() ? 0 : covLen[1]; }
};
