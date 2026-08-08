// Link: https://leetcode.com/problems/random-pick-with-blacklist/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(b) init, O(1) pick SC: O(b)
// Approach: let m = n - blacklist.size() be the count of valid numbers; pick uniformly from [0,m). For each blacklisted number < m, remap it to a whitelisted number >= m via a hash map, so pick() just does one lookup.
class Solution {
    unordered_map<int,int> remap;
    int m;
public:
    Solution(int n, vector<int>& blacklist) {
        m = n - blacklist.size();
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());
        int next = m;
        for (int b : blacklist) {
            if (b < m) {
                while (blackSet.count(next)) next++;
                remap[b] = next++;
            }
        }
    }

    int pick() {
        int x = rand() % m;
        return remap.count(x) ? remap[x] : x;
    }
};
