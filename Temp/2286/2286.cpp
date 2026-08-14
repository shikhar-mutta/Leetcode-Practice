// Link: https://leetcode.com/problems/booking-concert-tickets-in-groups/description/

#include <bits/stdc++.h>
using namespace std;

class BookMyShow {
    int n, m;
    vector<long long> maxAvail, sumAvail;
    vector<int> occupied;

    void build(int node, int lo, int hi) {
        if (lo == hi) {
            maxAvail[node] = m;
            sumAvail[node] = m;
            return;
        }
        int mid = (lo + hi) / 2;
        build(node*2, lo, mid);
        build(node*2+1, mid+1, hi);
        maxAvail[node] = max(maxAvail[node*2], maxAvail[node*2+1]);
        sumAvail[node] = sumAvail[node*2] + sumAvail[node*2+1];
    }

    void update(int node, int lo, int hi, int idx, long long val) {
        if (lo == hi) {
            maxAvail[node] = val;
            sumAvail[node] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (idx <= mid) update(node*2, lo, mid, idx, val);
        else update(node*2+1, mid+1, hi, idx, val);
        maxAvail[node] = max(maxAvail[node*2], maxAvail[node*2+1]);
        sumAvail[node] = sumAvail[node*2] + sumAvail[node*2+1];
    }

    // leftmost row in [0,maxRow] with availability >= k, or -1
    int queryLeftmost(int node, int lo, int hi, int maxRow, long long k) {
        if (lo > maxRow || maxAvail[node] < k) return -1;
        if (lo == hi) return lo;
        int mid = (lo + hi) / 2;
        int left = queryLeftmost(node*2, lo, mid, maxRow, k);
        if (left != -1) return left;
        return queryLeftmost(node*2+1, mid+1, hi, maxRow, k);
    }

    long long querySum(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) return sumAvail[node];
        int mid = (lo + hi) / 2;
        return querySum(node*2, lo, mid, l, r) + querySum(node*2+1, mid+1, hi, l, r);
    }

public:
    BookMyShow(int n, int m) : n(n), m(m) {
        maxAvail.assign(4 * n, 0);
        sumAvail.assign(4 * n, 0);
        occupied.assign(n, 0);
        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow) {
        int row = queryLeftmost(1, 0, n - 1, maxRow, k);
        if (row == -1) return {};
        int seatStart = occupied[row];
        occupied[row] += k;
        update(1, 0, n - 1, row, m - occupied[row]);
        return {row, seatStart};
    }

    bool scatter(int k, int maxRow) {
        long long total = querySum(1, 0, n - 1, 0, maxRow);
        if (total < k) return false;
        int row = queryLeftmost(1, 0, n - 1, maxRow, 1);
        while (k > 0) {
            long long avail = m - occupied[row];
            long long take = min((long long)k, avail);
            occupied[row] += take;
            k -= take;
            update(1, 0, n - 1, row, m - occupied[row]);
            row++;
        }
        return true;
    }
};
