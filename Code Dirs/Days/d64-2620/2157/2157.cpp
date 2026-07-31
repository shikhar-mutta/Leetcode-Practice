// Link: https://leetcode.com/problems/groups-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26^2)  SC: O(n)
//  Approach: We can use a disjoint set union (DSU) data structure to group the strings based on their character sets. We can represent each string as a bitmask of its characters, where each bit represents whether a character is present in the string or not. We can then iterate through the strings and for each string, we can generate all possible bitmasks by adding, removing, or replacing a character in the string. We can then check if any of these bitmasks have already been seen and if so, we can unite the current string with the string that has the same bitmask. Finally, we can return the number of groups and the size of the largest group.
template <class T>
using vec = vector<T>;

struct DSU
{
    vec<int> pr, sz;
    int cmps;
    DSU(int n) : pr(n), sz(n, 1), cmps{n} { ranges::iota(pr, 0); }
    inline int find(int x) { return pr[x] == x ? x : pr[x] = find(pr[x]); }
    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        pr[b] = a;
        sz[a] += sz[b];
        cmps--;
    }
};

class Solution
{
public:
    vec<int> groupStrings(vec<string> &words)
    {
        auto n = words.size();
        vec<unsigned> masks(n);
        unordered_map<unsigned, int> mask_pos;
        mask_pos.reserve(n);
        mask_pos.max_load_factor(0.7);
        auto masker = [](string_view s)
        {
            unsigned m{};
            for (char c : s)
                m |= 1u << (c - 'a');
            return m;
        };
        DSU ds(n);
        for (int i = 0; i < n; i++)
        {
            auto m = masker(words[i]);
            masks[i] = m;
            auto [it, _] = mask_pos.try_emplace(m, i);
            ds.unite(it->second, i);
        }
        auto e = mask_pos.end();
        for (int idx = 0; idx < n; idx++)
        {
            auto mask = masks[idx];
            for (int i = 0; i < 26; i++)
            {
                if (!(mask & (1u << i)))
                {
                    auto m = mask | (1u << i); // add a char
                    if (auto it = mask_pos.find(m); it != e)
                        ds.unite(it->second, idx);
                }
                else
                {
                    auto m = mask & ~(1u << i); // remove a char
                    if (auto it = mask_pos.find(m); it != e)
                        ds.unite(it->second, idx);
                    for (int j = i + 1; j < 26; j++)
                    {
                        if (m & (1u << j))
                            continue;
                        auto m2 = m | (1u << j); // replace with another
                        if (auto it = mask_pos.find(m2); it != e)
                            ds.unite(it->second, idx);
                    }
                }
            }
        }
        return {ds.cmps, *ranges::max_element(ds.sz)};
    }
};
