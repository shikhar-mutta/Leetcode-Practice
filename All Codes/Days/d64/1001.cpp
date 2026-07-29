// Link: https://leetcode.com/problems/grid-illumination/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(lamps + queries)  SC: O(lamps)
// Approach: track lit counts per row, column, diagonal (r-c), and
// anti-diagonal (r+c) in hashmaps (avoids an O(n^2) grid). For each
// query, the cell is lit iff any of its four counts is > 0; then turn
// off that lamp and its 8 neighbors (removing them from all four maps
// if present) before moving to the next query.
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps,
                                 vector<vector<int>> &queries)
    {
        const size_t size = queries.size();
        const size_t sizeL = lamps.size();
        std::vector<int> result;
        result.reserve(size);
        std::unordered_map<int32_t, int32_t> rows, cols;
        std::unordered_map<int64_t, int32_t> diag1, diag2;
        std::unordered_set<uint64_t> lampsSet;
        lampsSet.reserve(sizeL);
        rows.reserve(sizeL);
        cols.reserve(sizeL);
        diag1.reserve(sizeL);
        diag2.reserve(sizeL);
        for (const auto &lamp : lamps)
        {
            const int r = lamp[0];
            const int c = lamp[1];
            const uint64_t key =
                (static_cast<uint64_t>(r) << 32) | static_cast<uint32_t>(c);
            if (lampsSet.insert(key).second)
            {
                rows[r]++;
                cols[c]++;
                diag1[r - c]++;
                diag2[r + c]++;
            }
        }

        auto isIlluminated = [](const auto &m, auto key)
        {
            auto it = m.find(key);
            return it != m.end() && it->second > 0;
        };

        for (const auto &query : queries)
        {
            const int r = query[0];
            const int c = query[1];
            if (isIlluminated(rows, r) || isIlluminated(cols, c) ||
                isIlluminated(diag1, static_cast<int64_t>(r) - c) ||
                isIlluminated(diag2, static_cast<int64_t>(r) + c))
                result.push_back(1);
            else
                result.push_back(0);
            for (int i = r - 1; i <= r + 1; ++i)
                for (int j = c - 1; j <= c + 1; ++j)
                    if (i >= 0 && i < n && j >= 0 && j < n)
                    {
                        const uint64_t key = (static_cast<uint64_t>(i) << 32) |
                                             static_cast<uint32_t>(j);
                        if (lampsSet.erase(key))
                        {
                            rows[i]--;
                            cols[j]--;
                            diag1[static_cast<int64_t>(i) - j]--;
                            diag2[static_cast<int64_t>(i) + j]--;
                        }
                    }
        }
        return result;
    }
};