// Link: https://leetcode.com/problems/alternating-groups-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q log n) where n is the length of colors and q is the number of queries
// SC: O(n) where n is the length of colors
// Approach: We can use a Fenwick tree to keep track of the number of splits and the sum of lengths of blocks between splits. We can also use a set to keep track of the indices of splits. For each query, we can update the Fenwick tree and the set accordingly. Finally, we can return the number of alternating groups after processing all queries.
class Fenwick
{
    int n;
    vector<long long> tree_cnt;
    vector<long long> tree_sum;

public:
    Fenwick(int n) : n(n), tree_cnt(n + 2, 0), tree_sum(n + 2, 0) {}

    void add(int idx, int val)
    {
        if (idx <= 0 || idx > n)
            return;
        long long delta_cnt = val;
        long long delta_sum = (long long)idx * val;
        for (; idx <= n; idx += idx & -idx)
        {
            tree_cnt[idx] += delta_cnt;
            tree_sum[idx] += delta_sum;
        }
    }

    pair<long long, long long> query_range(int left)
    {
        long long total_cnt = 0, total_sum = 0;
        auto query_prefix = [&](int idx)
        {
            long long c = 0, s = 0;
            for (; idx > 0; idx -= idx & -idx)
            {
                c += tree_cnt[idx];
                s += tree_sum[idx];
            }
            return make_pair(c, s);
        };
        auto right_res = query_prefix(n);
        auto left_res = query_prefix(left - 1);
        return {right_res.first - left_res.first,
                right_res.second - left_res.second};
    }
};

class Solution
{
public:
    vector<int> numberOfAlternatingGroups(vector<int> &colors,
                                          vector<vector<int>> &queries)
    {
        int n = colors.size();
        Fenwick bit(n);
        set<int> splits;

        auto get_block_len = [&](int left_split, int right_split)
        {
            if (left_split < right_split)
                return right_split - left_split;
            return right_split + n - left_split;
        };

        auto add_split = [&](int idx)
        {
            if (splits.empty())
            {
                // Transitioning from 0 splits to 1 split:
                // Remove the virtual full circular block of length N
                bit.add(n, -1);
                splits.insert(idx);
                // The single split forms a block of length N with itself
                // circularly
                bit.add(n, 1);
                return;
            }

            auto it = splits.lower_bound(idx);
            int nxt = (it == splits.end()) ? *splits.begin() : *it;
            int prv = (it == splits.begin()) ? *splits.rbegin() : *prev(it);

            bit.add(get_block_len(prv, nxt), -1);
            bit.add(get_block_len(prv, idx), 1);
            bit.add(get_block_len(idx, nxt), 1);
            splits.insert(idx);
        };

        auto remove_split = [&](int idx)
        {
            if (splits.size() == 1 && splits.count(idx))
            {
                // Transitioning from 1 split to 0 splits:
                bit.add(n, -1);
                splits.erase(idx);
                // Array becomes completely alternating
                bit.add(n, 1);
                return;
            }

            auto it = splits.find(idx);
            auto nxt_it = next(it) == splits.end() ? splits.begin() : next(it);
            auto prv_it = it == splits.begin() ? prev(splits.end()) : prev(it);

            int nxt = *nxt_it;
            int prv = *prv_it;

            bit.add(get_block_len(prv, idx), -1);
            bit.add(get_block_len(idx, nxt), -1);
            bit.add(get_block_len(prv, nxt), 1);
            splits.erase(it);
        };

        // Seed initial split conditions
        for (int i = 0; i < n; ++i)
        {
            if (colors[i] == colors[(i + 1) % n])
            {
                splits.insert(i);
            }
        }

        if (splits.empty())
        {
            bit.add(n, 1);
        }
        else
        {
            int first = *splits.begin();
            int prev_split = first;
            for (auto it = next(splits.begin()); it != splits.end(); ++it)
            {
                bit.add(*it - prev_split, 1);
                prev_split = *it;
            }
            bit.add(first + n - prev_split, 1);
        }

        vector<int> ans;
        for (const auto &q : queries)
        {
            if (q[0] == 1)
            {
                int sz = q[1];
                if (splits.empty())
                {
                    ans.push_back(n);
                }
                else
                {
                    auto [cnt, sum] = bit.query_range(sz);
                    long long res = sum - (sz - 1) * cnt;
                    ans.push_back(res);
                }
            }
            else
            {
                int idx = q[1];
                int col = q[2];
                if (colors[idx] == col)
                    continue;

                int left_neighbor = (idx - 1 + n) % n;
                int right_neighbor = (idx + 1) % n;

                if (colors[left_neighbor] == colors[idx])
                    remove_split(left_neighbor);
                if (colors[idx] == colors[right_neighbor])
                    remove_split(idx);

                colors[idx] = col;

                if (colors[left_neighbor] == colors[idx])
                    add_split(left_neighbor);
                if (colors[idx] == colors[right_neighbor])
                    add_split(idx);
            }
        }
        return ans;
    }
};
