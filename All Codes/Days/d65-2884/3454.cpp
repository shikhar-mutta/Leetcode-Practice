// Link: https://leetcode.com/problems/separate-squares-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
// Approach: We can use a segment tree to keep track of the covered segments in the x-axis. We can use a sweep line algorithm to process the events in the y-axis. For each event, we can update the segment tree and calculate the area covered by the squares. We can then find the y-coordinate that divides the area into two equal parts.
class Solution
{
public:
    vector<int> values;
    vector<int> st;
    vector<int> ct; // count edges coverting current segment
    static constexpr int left(int i) noexcept { return i << 1; }
    static constexpr int right(int i) noexcept { return i << 1 | 1; }

    void update(int idx, int l, int r, int ql, int qr, int delta)
    {
        if (r - l < 1)
            return;
        if (l >= ql && r <= qr)
        {
            ct[idx] += delta;
        }
        else
        {
            const auto mid = (r - l) / 2 + l;
            if (ql < mid)
            {
                update(left(idx), l, mid, ql, qr, delta);
            }
            if (qr > mid)
            {
                update(right(idx), mid, r, ql, qr, delta);
            }
        }
        if (ct[idx] > 0)
        {
            st[idx] = values[r] - values[l];
        }
        else
        {
            if (r - l == 1)
                st[idx] = 0; // endpoint segments, if no count, no interval coverage
            else
                st[idx] = st[left(idx)] + st[right(idx)]; // combine left interval with right segment's
        }
    }

    double separateSquares(vector<vector<int>> &squares)
    {
        for (const auto &s : squares)
        {
            values.push_back(s[0]);
            values.push_back(s[0] + s[2]);
        }
        sort(values.begin(), values.end());
        values.erase(std::unique(values.begin(), values.end()), values.end());
        const auto N = values.size();
        st.resize(4 * N);
        ct.assign(4 * N, 0);

        vector<tuple<int, int, int, int>> events; // {y, xl, xr, type}
        for (auto &s : squares)
        {
            const int xl = s[0], yl = s[1], edge = s[2];
            events.emplace_back(yl, xl, xl + edge, 1);         // add edge to segment
            events.emplace_back(yl + edge, xl, xl + edge, -1); // remove edge
        }
        sort(events.begin(), events.end());
        int prevH = get<0>(events[0]);
        double area{0};
        vector<tuple<int, int, double>> records;

        for (const auto [y, xl, xr, t] : events)
        {
            if (y > prevH)
            {
                const auto segment = st[1]; // horizontal covered segments total
                const double h = y - prevH;
                area += segment * h;
                records.emplace_back(prevH, segment, h);
                prevH = y;
            }
            auto vl = lower_bound(values.begin(), values.end(), xl) - values.begin();
            auto vr = lower_bound(values.begin(), values.end(), xr) - values.begin();
            update(1, 0, N - 1, vl, vr, t);
        }

        double half = area / 2.0L;
        double total = 0;
        for (const auto [prevY, seg, h] : records)
        {
            // cout << format("proc segment y={}, width {}, h {}\n", prevY, seg, h);
            if (total + seg * h >= half)
            {
                return prevY + (half - total) / seg;
            }
            total += seg * h;
        }
        return 0;
    }
};
