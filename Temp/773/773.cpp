// Link: https://leetcode.com/problems/sliding-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(6! * 6) SC: O(6!)
// Approach: encode the 2x3 board as a 6-char string; BFS over states, swapping the '0' position with each valid neighbor per the fixed 2x3 adjacency list.
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto& row : board) for (int x : row) start += char('0'+x);
        string target = "123450";
        vector<vector<int>> adj = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> visited = {start};
        queue<string> q;
        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (cur == target) return steps;
                int zero = cur.find('0');
                for (int nb : adj[zero]) {
                    string next = cur;
                    swap(next[zero], next[nb]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
