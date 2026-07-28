// Link: https://leetcode.com/problems/booking-concert-tickets-in-groups/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log n) per gather, O(maxRow) worst case per scatter  SC: O(n)
// Approach: segment tree over rows storing (max free seats in range, sum
// free seats in range). gather: descend to find the leftmost row within
// [0,maxRow] whose free seats >= k (using max), book there. scatter:
// check sum of free seats in [0,maxRow] >= k, then walk rows left to
// right filling greedily until k seats are placed.
class BookMyShow {
    int n, m;
    vector<long long> segMax, segSum;
    vector<long long> seatsUsed;

    void build(int node, int l, int r) {
        if (l == r) { segMax[node] = m; segSum[node] = m; return; }
        int mid = (l + r) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);
        segMax[node] = max(segMax[node*2], segMax[node*2+1]);
        segSum[node] = segSum[node*2] + segSum[node*2+1];
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) { segMax[node] = val; segSum[node] = val; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(node*2, l, mid, idx, val);
        else update(node*2+1, mid+1, r, idx, val);
        segMax[node] = max(segMax[node*2], segMax[node*2+1]);
        segSum[node] = segSum[node*2] + segSum[node*2+1];
    }

    int queryFirstRow(int node, int l, int r, int maxRow, long long k) {
        if (l > maxRow || segMax[node] < k) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        int res = queryFirstRow(node*2, l, mid, maxRow, k);
        if (res != -1) return res;
        return queryFirstRow(node*2+1, mid+1, r, maxRow, k);
    }

    long long querySum(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return segSum[node];
        int mid = (l + r) / 2;
        return querySum(node*2, l, mid, ql, qr) + querySum(node*2+1, mid+1, r, ql, qr);
    }

public:
    BookMyShow(int n_, int m_) {
        n = n_; m = m_;
        segMax.assign(4*n, 0);
        segSum.assign(4*n, 0);
        seatsUsed.assign(n, 0);
        if (n > 0) build(1, 0, n-1);
    }

    vector<int> gather(int k, int maxRow) {
        int row = queryFirstRow(1, 0, n-1, maxRow, k);
        if (row == -1) return {};
        int seat = (int)seatsUsed[row];
        seatsUsed[row] += k;
        update(1, 0, n-1, row, m - seatsUsed[row]);
        return {row, seat};
    }

    bool scatter(int k, int maxRow) {
        long long avail = querySum(1, 0, n-1, 0, maxRow);
        if (avail < k) return false;
        for (int row = 0; row <= maxRow && k > 0; row++) {
            long long free = m - seatsUsed[row];
            if (free == 0) continue;
            long long take = min((long long)k, free);
            seatsUsed[row] += take;
            k -= take;
            update(1, 0, n-1, row, m - seatsUsed[row]);
        }
        return true;
    }
};
