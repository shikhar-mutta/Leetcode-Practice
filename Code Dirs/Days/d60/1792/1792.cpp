// Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
// Approach: Priority Queue
//   1. We can use a priority queue to store the classes based on the maximum increase in pass ratio that can be achieved by adding an extra student to the class.
//   2. For each extra student, we can pop the class with the maximum increase in pass ratio from the priority queue, add the extra student to that class, and push it back into the priority queue.
//   3. Finally, we can calculate the average pass ratio of all classes and return it.
class Solution
{
private:
    static constexpr uint8_t VSH = 17;
    static constexpr uint VMASK = (1u << VSH) - 1u;

public:
    static double maxAverageRatio(vector<vector<int>> &classes, uint s)
    {
        const uint n = classes.size();
        if (n == 1)
        {
            const auto &x = classes.front();
            const uint p = x[0], t = x[1];
            return (double)(p + s) / (t + s);
        }
        vector<uint64_t> &qvec = (vector<uint64_t> &)classes;
        uint64_t *const qdata = qvec.data();
        const auto cmp = [](const uint64_t a, const uint64_t b)
        {
            const uint t = a >> VSH, p = a & VMASK, u = b >> VSH, v = b & VMASK;
            return (t - p) * (u + 1ull) * u < (u - v) * (t + 1ull) * t;
        };
        uint m = 0;
        double res = 0.;
        for (const auto &x : classes)
        {
            const uint p = x[0], t = x[1];
            if (p != t)
                qdata[m++] = (uint64_t(t) << VSH) + p;
            res += (double)p / t;
        }
        switch (m)
        {
        case 0:
            qvec.clear();
            return 1.;
        case 1:
        {
            const auto x = *qdata;
            qvec.clear();
            const uint p = x & VMASK, t = x >> VSH;
            return (double)(p + s) / (t + s);
        }
        }
        make_heap(qdata, qdata + m, cmp);
        while (true)
        {
            const uint64_t x = *qdata;
            const uint t = x >> VSH, p = x & VMASK, l = t - p;
            pop_heap(qdata, qdata + m--, cmp);
            const uint64_t y = *qdata;
            const uint u = y >> VSH, v = y & VMASK;
            const uint z = floor(sqrt((t - p) * (u + 1ull) * u / double(u - v) +
                                      0.75)),
                       f = (s + m) / (m + 1u) / 4u, d = max(z, t + f + !f) - t,
                       e = min(d, s);
            res += (p + e) / double(t + e) - p / (double)t;
            s -= e;
            if (!s)
                break;
            qdata[m++] = x + e + (uint64_t(e) << VSH);
            push_heap(qdata, qdata + m, cmp);
        }
        qvec.clear();
        return res / n;
    }
};