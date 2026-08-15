// Link: https://leetcode.com/problems/alien-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total chars + 26)  SC: O(1) (bounded alphabet)
// Approach: derive edges from the first differing char between each adjacent word pair (invalid if
// a later word is a strict prefix of an earlier one), then Kahn's topological sort over the 26 letters
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        for (auto& w : words) for (char c : w) { adj[c]; indeg[c]; }

        for (int i = 0; i + 1 < (int)words.size(); i++) {
            string& a = words[i];
            string& b = words[i+1];
            int minLen = min(a.size(), b.size());
            bool found = false;
            for (int j = 0; j < minLen; j++) {
                if (a[j] != b[j]) {
                    if (!adj[a[j]].count(b[j])) {
                        adj[a[j]].insert(b[j]);
                        indeg[b[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && a.size() > b.size()) return "";
        }

        queue<char> q;
        for (auto& [c, d] : indeg) if (d == 0) q.push(c);
        string res;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            res += c;
            for (char nb : adj[c]) {
                if (--indeg[nb] == 0) q.push(nb);
            }
        }
        if (res.size() != indeg.size()) return "";
        return res;
    }
};
