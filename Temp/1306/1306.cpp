// Link: https://leetcode.com/problems/jump-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (arr[i] == 0) return true;
            for (int ni : {i + arr[i], i - arr[i]}) {
                if (ni >= 0 && ni < n && !visited[ni]) {
                    visited[ni] = true;
                    q.push(ni);
                }
            }
        }
        return false;
    }
};
