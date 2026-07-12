// Link: https://leetcode.com/problems/smallest-string-with-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
// Approach:
// 1. We can use union-find to group the indices of the string into connected components based on the pairs of indices that can be swapped.
// 2. For each connected component, we can extract the characters at those indices, sort them, and then place them back into the string in sorted order.

class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto &p : pairs)
            parent[find(p[0])] = find(p[1]);

        // group indices by component root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        // within each component, sort the chars and place them back
        // onto the (already ascending) index list
        for (auto &[root, idx] : groups)
        {
            string chars;
            for (int i : idx)
                chars += s[i];
            sort(chars.begin(), chars.end());
            for (int k = 0; k < (int)idx.size(); k++)
                s[idx[k]] = chars[k];
        }
        return s;
    }
};
