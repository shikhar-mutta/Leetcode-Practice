// Link: https://leetcode.com/problems/substring-xor-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * max_bits + q) where max_bits = 30 (query values fit in ~30 bits)
// SC: O(n * max_bits) for the value->earliest-start-index map
// Approach: query[0]^first ^ query[1] = target value to find as a
// substring of s (interpreted as binary), and any target needs at most
// ~30 bits since queries[i][*] <= 1e9. So precompute, for every bit
// length 1..30, every substring of that exact length's integer value via
// a rolling window, keeping only the FIRST (leftmost, hence shortest
// leading-zero-free) occurrence per value. A query's answer is
// x = query[0]^query[1]: look up its earliest occurrence, adjusting the
// start index down for values needing fewer bits than a full 30-length
// window (handles leading zeros correctly), or -1 -1 if never seen.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<vector<int>> substringXorQueries(const string& s,
                                            vector<vector<int>>& queries) {
        constexpr int max_bits = 30;
        int n = s.size();
        unordered_map<int, int> mp(max_bits * n);
        for (int bits = 1; bits <= max_bits; ++bits) {
            int num = 0;
            for (int i = 0; i < n; ++i) {
                num = (num << 1) | (s[i] - '0');
                if (bits == 1 ||
                    (i + 1 >= bits && bit_width(1u * num) == bits)) {
                    mp.try_emplace(num, i);
                    num &= ~(1 << (bits - 1));
                }
            }
        }
        vector<vector<int>> ans;
        ans.reserve(queries.size());
        for (auto& query : queries) {
            int x = query[0] ^ query[1];
            auto it = mp.find(x);
            if (it != mp.end())
                ans.push_back(
                    {it->second + min(0, 1 - bit_width(1u * x)), it->second});
            else
                ans.push_back({-1, -1});
        }
        return ans;
    }
};
