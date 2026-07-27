// Link: https://leetcode.com/problems/number-of-prefix-connected-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of word lengths) SC: O(n*k)
// Approach: words with length < k are ignored; group the rest by their
// first k characters and count groups with at least 2 members.
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> groups;
        for (auto& w : words) {
            if ((int)w.size() < k) continue;
            groups[w.substr(0, k)]++;
        }
        int ans = 0;
        for (auto& [key, cnt] : groups) if (cnt >= 2) ans++;
        return ans;
    }
};
