// Link: https://leetcode.com/problems/map-sum-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k) insert, O(n*L) sum (linear scan) SC: O(n)
// Approach: store key->val in a hash map; sum(prefix) linearly scans all keys checking prefix match and accumulates values.
class MapSum {
    unordered_map<string,int> vals;
public:
    MapSum() {}

    void insert(string key, int val) {
        vals[key] = val;
    }

    int sum(string prefix) {
        int total = 0;
        for (auto& [k, v] : vals) {
            if (k.size() >= prefix.size() && k.compare(0, prefix.size(), prefix) == 0) total += v;
        }
        return total;
    }
};
