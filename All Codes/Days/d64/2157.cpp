// Link: https://leetcode.com/problems/groups-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 26^2)  SC: O(n)
// Approach: represent each word as a 26-bit letter-presence mask; connect
// (Union-Find) words whose masks are reachable via add-one-bit,
// delete-one-bit, or delete-one-add-one (replace) since those are exactly
// the allowed single-letter operations that preserve group membership.
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> maskToIdx;
        vector<int> masks(n);
        for (int i = 0; i < n; i++) {
            int m = 0;
            for (char c : words[i]) m |= (1 << (c - 'a'));
            masks[i] = m;
            maskToIdx[m] = i;
        }
        vector<int> par(n), sz(n, 1);
        iota(par.begin(), par.end(), 0);
        function<int(int)> find = [&](int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a; sz[a] += sz[b];
        };
        for (int i = 0; i < n; i++) {
            int m = masks[i];
            // delete a letter
            for (int b = 0; b < 26; b++) {
                if (!(m & (1 << b))) continue;
                int nm = m & ~(1 << b);
                if (maskToIdx.count(nm)) unite(i, maskToIdx[nm]);
                // replace: delete b then add c
                for (int c = 0; c < 26; c++) {
                    if (c == b || (m & (1 << c))) continue;
                    int rm = nm | (1 << c);
                    if (maskToIdx.count(rm)) unite(i, maskToIdx[rm]);
                }
            }
            // add a letter
            for (int b = 0; b < 26; b++) {
                if (m & (1 << b)) continue;
                int nm = m | (1 << b);
                if (maskToIdx.count(nm)) unite(i, maskToIdx[nm]);
            }
        }
        unordered_map<int, int> groupSize;
        for (int i = 0; i < n; i++) groupSize[find(i)]++;
        int numGroups = groupSize.size();
        int maxSize = 0;
        for (auto& [k, v] : groupSize) maxSize = max(maxSize, v);
        return {numGroups, maxSize};
    }
};
