// Link: https://leetcode.com/problems/cracking-the-safe/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k^n) SC: O(k^n)
// Approach: Hierholzer's algorithm for an Eulerian circuit on the de Bruijn graph where nodes are (n-1)-length strings and edges are n-length strings (appending a digit). Greedily DFS consuming each edge once; post-order append gives the circuit, which visits every possible n-length combination exactly once.
class Solution {
    unordered_set<string> visitedEdges;
    string result;
    int n, k;
    void dfs(const string& node) {
        for (int d = 0; d < k; d++) {
            string edge = node + char('0'+d);
            if (!visitedEdges.count(edge)) {
                visitedEdges.insert(edge);
                dfs(edge.substr(1));
                result += char('0'+d);
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        this->n = n; this->k = k;
        string start(n-1, '0');
        dfs(start);
        result += start;
        return result;
    }
};
