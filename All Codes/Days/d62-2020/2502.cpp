// Link: https://leetcode.com/problems/design-memory-allocator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n + k) per allocate/freeMemory (k = current number of
//     allocated blocks scanned in the worst case)
// SC: O(k)
// Approach: keep an ordered map from a block's starting index to its
// size, plus a sentinel entry at index n marking the end of memory.
// allocate scans the map in order tracking the free-space end after each
// occupied block, stopping at the first gap wide enough for the request;
// freeMemory looks up all indices previously assigned to an mID and
// removes them, returning the total freed size.
class Allocator {
public:
    Allocator(int n) {
        m_size = n;
        m_idxSizes.emplace(n, 0);
    }

    int allocate(int size, int mID) {
        int idx = 0;

        for (const auto& p : m_idxSizes) {
            if (p.first - idx >= size) {
                // Block found
                break;
            }

            idx = p.first + p.second;
        }

        if (idx >= m_size) {
            return -1;
        }

        m_idxSizes.emplace(idx, size);
        m_mIdIndices[mID].push_back(idx);
        return idx;
    }

    int freeMemory(int mID) {
        int size = 0;

        if (!m_mIdIndices.count(mID)) {
            return size;
        }

        for (const auto& idx : m_mIdIndices[mID]) {
            size += m_idxSizes[idx];
            m_idxSizes.erase(idx);
        }
        m_mIdIndices.erase(mID);

        return size;
    }

private:
    int m_size;

    map<int, int> m_idxSizes;
    unordered_map<int, vector<int>> m_mIdIndices;
};
