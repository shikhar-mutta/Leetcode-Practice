// Link: https://leetcode.com/problems/booking-concert-tickets-in-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per gather/scatter, amortized O(log n) per scatter (each merge removes an interval)  SC: O(n)
//  Approach: maintain a segment tree of disjoint intervals keyed by right endpoint.
//  On gather(k, maxRow): repeatedly find overlapping/adjacent intervals, merge them
//  into [l,r], subtracting their length from the running total, then insert
//  the merged interval and add its length back.
template <typename T>
struct seg_tree
{
    int S;

    T identity;
    vector<T> value;

    seg_tree<T>(int _S, T val)
    {
        S = _S, identity = T();
        value.resize(2 * S + 1, val);
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] * value[2 * i + 1];
    }

    void upd(int i, T v)
    {
        i += S;
        value[i] = v;
        while (i > 1)
        {
            i /= 2;
            value[i] = value[2 * i] * value[2 * i + 1];
        }
    }

    T query(int i, int j)
    {
        T res_left = identity, res_right = identity;
        for (i += S, j += S; i <= j; i /= 2, j /= 2)
        {
            if ((i & 1) == 1)
                res_left = res_left * value[i++];
            if ((j & 1) == 0)
                res_right = value[j--] * res_right;
        }
        return res_left * res_right;
    }
};

struct TM
{
    long long M;
    TM(long long x = 0) : M(x) {}
    TM operator*(const TM &rhs) const { return max(M, rhs.M); }
};

struct TS
{
    long long S;
    TS(long long x = 0) : S(x) {}
    TS operator*(const TS &rhs) const { return S + rhs.S; }
};

int pot2(int n)
{
    while (n & (n - 1))
        n++;
    return n;
}

class BookMyShow
{
    seg_tree<TM> SM;
    seg_tree<TS> SS;
    int mm;
    vector<int> sz;
    int smallest;

public:
    BookMyShow(int n, int m)
        : SM(pot2(n), m), SS(pot2(n), m), mm(m), sz(pot2(n), m), smallest(0) {}

    vector<int> gather(int k, int maxRow)
    {

        // traverse down the tree finding the best option...
        int node = 1;
        int m = 0, M = SM.S;

        while (node < SM.S)
        {
            int me = (m + M) / 2;
            bool left = true;
            node *= 2;
            if (me <= maxRow)
            {
                // can go to both left and right... can we go left?
                left = SM.value[node].M >= k;
            }
            if (left)
            {
                M = me;
            }
            else
            {
                node++;
                m = me;
            }
        }
        TM val = SM.value[node];
        if (val.M < k)
            return {};
        val = SM.value[node];

        // ok, can do... go ahead:
        const int which = node - SM.S;
        sz[which] -= k;
        SM.upd(which, sz[which]);
        SS.upd(which, sz[which]);
        return {which, (int)(mm - val.M)};
    }

    bool scatter(int k, int maxRow)
    {
        const TS val = SS.query(smallest, maxRow);
        if (val.S < k)
            return false;

        // allocate. Let's do this :)
        while (k)
        {
            int to_remove = min(k, sz[smallest]);
            k -= to_remove;
            sz[smallest] -= to_remove;
            SS.upd(smallest, sz[smallest]);
            SM.upd(smallest, sz[smallest]);

            if (!sz[smallest])
                smallest++;
        }
        return true;
    }
};
