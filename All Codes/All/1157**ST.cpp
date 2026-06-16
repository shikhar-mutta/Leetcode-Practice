// Link: https://leetcode.com/problems/online-majority-element-in-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class MajorityChecker
{
    int n;
    vector<int> arr;
    unordered_map<int, vector<int>> pos; // value -> sorted indices

    // Segment tree holding the Boyer-Moore (candidate, count) of each range.
    vector<int> segCand, segCnt;

    // Boyer-Moore merge of two (candidate,count) votes.
    pair<int, int> mrg(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return {a.first, a.second + b.second};
        if (a.second >= b.second)
            return {a.first, a.second - b.second};
        return {b.first, b.second - a.second};
    }

    // build the segment tree
    void build(int node, int lo, int hi)
    {
        if (lo == hi) // leaf
        {
            segCand[node] = arr[lo];
            segCnt[node] = 1;
            return;
        }
        int mid = (lo + hi) / 2;
        build(2 * node, lo, mid);         // divide
        build(2 * node + 1, mid + 1, hi); // divide
        auto m = mrg({segCand[2 * node], segCnt[2 * node]},
                     {segCand[2 * node + 1], segCnt[2 * node + 1]}); // merge
        segCand[node] = m.first;                                     // candidate
        segCnt[node] = m.second;                                     // count
    }

    pair<int, int> queryVote(int node, int lo, int hi, int l, int r)
    { // Query the Boyer-Moore vote in [l,r]
        if (r < lo || hi < l)
            return {-1, 0};
        if (l <= lo && hi <= r)
            return {segCand[node], segCnt[node]};
        int mid = (lo + hi) / 2;
        return mrg(queryVote(2 * node, lo, mid, l, r),
                   queryVote(2 * node + 1, mid + 1, hi, l, r));
    }

public:
    MajorityChecker(vector<int> &a)
    {
        arr = a;
        n = arr.size();
        for (int i = 0; i < n; i++) // store the sorted indices of each value
            pos[arr[i]].push_back(i);
        segCand.assign(4 * n, -1); // -1 means no candidate
        segCnt.assign(4 * n, 0);   // 0 means no count
        build(1, 0, n - 1);
    }

    int query(int left, int right, int threshold)
    {
        // The only possible majority in [left,right] is its Boyer-Moore candidate.
        int cand = queryVote(1, 0, n - 1, left, right).first;
        if (cand == -1)
            return -1;
        // Verify true frequency in the range via binary search on its index list.
        auto &p = pos[cand];
        // freq of candidate
        int cnt = upper_bound(p.begin(), p.end(), right) - lower_bound(p.begin(), p.end(), left);
        return cnt >= threshold ? cand : -1;
    }
};
