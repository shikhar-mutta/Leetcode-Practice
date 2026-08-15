// Link: https://leetcode.com/problems/the-maze-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*log(m*n))  SC: O(m*n)
// Approach: Dijkstra where each "edge" is a full roll in one direction
// until hitting a wall or the hole; state cost = (distance, path string),
// compared lexicographically per problem rules ('d','l','r','u' order)
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<pair<int,string>>> best(m, vector<pair<int,string>>(n, {INT_MAX, ""}));
        best[ball[0]][ball[1]] = {0, ""};

        // directions in the required tie-break order: d, l, r, u
        vector<tuple<char,int,int>> dirs = {{'d',1,0},{'l',0,-1},{'r',0,1},{'u',-1,0}};

        using State = tuple<int,string,int,int>; // dist, path, r, c
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, "", ball[0], ball[1]});

        while (!pq.empty()) {
            auto [dist, path, r, c] = pq.top(); pq.pop();
            if (dist > best[r][c].first || (dist == best[r][c].first && path > best[r][c].second)) continue;

            for (auto& [ch, dr, dc] : dirs) {
                int nr = r, nc = c, steps = 0;
                bool foundHole = false;
                while (true) {
                    int tr = nr + dr, tc = nc + dc;
                    if (tr < 0 || tr >= m || tc < 0 || tc >= n || maze[tr][tc] == 1) break;
                    nr = tr; nc = tc; steps++;
                    if (nr == hole[0] && nc == hole[1]) { foundHole = true; break; }
                }
                if (nr == r && nc == c) continue;

                int ndist = dist + steps;
                string npath = path + ch;
                if (ndist < best[nr][nc].first || (ndist == best[nr][nc].first && npath < best[nr][nc].second)) {
                    best[nr][nc] = {ndist, npath};
                    if (!foundHole) pq.push({ndist, npath, nr, nc});
                }
            }
        }

        auto& res = best[hole[0]][hole[1]];
        return res.first == INT_MAX ? "impossible" : res.second;
    }
};
