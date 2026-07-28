// Link: https://leetcode.com/problems/sliding-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((m*n)!)  bounded in practice since board is fixed 2x3  SC: same
// Approach: encode the 2x3 board as a 6-char string; BFS over states,
// swapping the '0' tile with each valid neighbor (precomputed adjacency
// for the flattened 2x3 grid) to generate successor states, until the
// target "123450" is reached.
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto& row : board) for (int v : row) start += char('0' + v);
        string target = "123450";
        if (start == target) return 0;

        vector<vector<int>> adj = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> visited;
        visited.insert(start);
        queue<string> q;
        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                string cur = q.front(); q.pop();
                int zero = cur.find('0');
                for (int nb : adj[zero]) {
                    string next = cur;
                    swap(next[zero], next[nb]);
                    if (next == target) return steps;
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
