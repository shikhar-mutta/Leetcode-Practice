// Link: https://leetcode.com/problems/cracking-the-safe/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(k^n)  SC: O(k^n)
// Approach: build a de Bruijn sequence via Hierholzer's algorithm on the
// graph where nodes are (n-1)-length strings over digits 0..k-1 and an
// edge node->node[1:]+d exists for each digit d (representing the
// n-length password node+d). A post-order DFS from the all-zero node,
// appending the edge digit after recursing, produces the Eulerian
// circuit in reverse; reversing it and prepending the start node gives
// the shortest string containing every possible password as a substring.
class Solution {
    unordered_set<string> visited;
    string ans;
    int k;
    void dfs(const string& node) {
        for (int d = 0; d < k; d++) {
            string edge = node + char('0' + d);
            if (!visited.count(edge)) {
                visited.insert(edge);
                dfs(edge.substr(1));
                ans += char('0' + d);
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        this->k = k;
        string start(n - 1, '0');
        dfs(start);
        reverse(ans.begin(), ans.end());
        return start + ans;
    }
};
