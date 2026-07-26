// Link: https://leetcode.com/problems/number-of-black-blocks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k log k) where k = coordinates.size()
// SC: O(k)
// Approach: every 2x2 block is identified by its top-left cell's flattened
// index. Each black cell belongs to up to 4 such blocks (itself as
// bottom-right/bottom-left/top-right/top-left corner), so push that block's
// key for each valid direction (skipping ones that would go out of bounds).
// After sorting, each run of equal keys is one block containing that many
// black cells (1-4); tally into arr[1..4]. arr[0] (all-white blocks) is total
// blocks (m-1)*(n-1) minus however many blocks had at least one black cell.
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n,
                                       vector<vector<int>>& coordinates) {
        vector<long long> arr(5, 0);

        vector<long long> keys;
        keys.reserve(coordinates.size() * 4);

        for (auto& v : coordinates) {
            long long r = v[0], c = v[1];
            bool downOk = r != m - 1, rightOk = c != n - 1, upOk = r != 0,
                 leftOk = c != 0;
            if (downOk && rightOk)
                keys.push_back(r * n + c); // top-left (r,   c)
            if (upOk && rightOk)
                keys.push_back((r - 1) * n + c); // top-left (r-1, c)
            if (downOk && leftOk)
                keys.push_back(r * n + c - 1); // top-left (r,   c-1)
            if (upOk && leftOk)
                keys.push_back((r - 1) * n + c - 1); // top-left (r-1, c-1)
        }

        sort(keys.begin(), keys.end());

        long long blocksWithBlack = 0;
        for (size_t i = 0; i < keys.size();) {
            size_t j = i;
            while (j < keys.size() && keys[j] == keys[i])
                ++j;
            arr[j - i]++; // run length = # black cells in this block (1..4)
            ++blocksWithBlack;
            i = j;
        }

        arr[0] = (long long)(m - 1) * (n - 1) - blocksWithBlack;
        return arr;
    }
};
