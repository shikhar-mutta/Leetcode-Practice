// Link: https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0); // 0=unvisited,1=in current path,2=done
        vector<int> timeArr(n, -1);
        int globalTime = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i] != 0) continue;
            vector<int> path;
            int cur = i;
            while (cur != -1 && visited[cur] == 0) {
                visited[cur] = 1;
                timeArr[cur] = globalTime++;
                path.push_back(cur);
                cur = edges[cur];
            }
            if (cur != -1 && visited[cur] == 1) {
                ans = max(ans, globalTime - timeArr[cur]);
            }
            for (int node : path) visited[node] = 2;
        }
        return ans;
    }
};
