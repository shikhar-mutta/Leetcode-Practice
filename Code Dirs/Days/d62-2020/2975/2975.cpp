// Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(v^2 + h^2) – enumerate all O(v^2) vertical gaps and O(h^2) horizontal
//     gaps, where v = |vFences|+2, h = |hFences|+2 (both ≤ 602)
// SC: O(HASH_SIZE) = O(2^18) – fixed-size open-addressing hash table for
//     vertical gap lookup; replaces unordered_set for speed
// Approach: A square is formed by choosing two horizontal fences and two
// vertical fences with the same gap. Add boundary fences 1 and m/n. First,
// store all pairwise vertical gaps in a custom hash set. Then scan all
// pairwise horizontal gaps; if a gap also exists as a vertical gap, it is a
// valid square side. Track the maximum such gap and return gap^2 % MOD.
class Solution
{
    static const int HASH_SIZE = 1 << 18;
    int hashTable[HASH_SIZE];
    void insert(int val)
    {
        int h = (1LL * val * 2654435761u) & (HASH_SIZE - 1);
        while (hashTable[h] != 0)
        {
            if (hashTable[h] == val)
                return;
            h = (h + 1) & (HASH_SIZE - 1);
        }
        hashTable[h] = val;
    }
    bool contains(int val)
    {
        int h = (1LL * val * 2654435761u) & (HASH_SIZE - 1);
        while (hashTable[h] != 0)
        {
            if (hashTable[h] == val)
                return true;
            h = (h + 1) & (HASH_SIZE - 1);
        }
        return false;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences,
                           vector<int> &vFences)
    {
        const int MOD = 1'000'000'007;
        memset(hashTable, 0, sizeof(hashTable));
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        for (int i = 0; i < vFences.size(); ++i)
        {
            for (int j = i + 1; j < vFences.size(); ++j)
            {
                insert(abs(vFences[i] - vFences[j]));
            }
        }
        int max_gap = -1;
        for (int i = 0; i < hFences.size(); ++i)
        {
            for (int j = i + 1; j < hFences.size(); ++j)
            {
                int gap = abs(hFences[i] - hFences[j]);
                if (gap > max_gap && contains(gap))
                {
                    max_gap = gap;
                }
            }
        }
        if (max_gap == -1)
            return -1;
        return (1LL * max_gap * max_gap) % MOD;
    }
};