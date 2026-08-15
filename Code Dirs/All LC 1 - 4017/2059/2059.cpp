// Link: https://leetcode.com/problems/minimum-operations-to-convert-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        const int LO = 0, HI = 1000;
        vector<bool> visited(HI - LO + 1001, false); // offset by 1000 to allow negative-ish safety
        auto idx = [](int v) { return v + 1000; };
        if (start == goal) return 0;
        queue<int> q;
        q.push(start);
        visited[idx(start)] = true;
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                int cur = q.front(); q.pop();
                for (int n : nums) {
                    for (int op = 0; op < 3; op++) {
                        int nxt;
                        if (op == 0) nxt = cur + n;
                        else if (op == 1) nxt = cur - n;
                        else nxt = cur ^ n;
                        if (nxt == goal) return steps;
                        if (nxt < -1000 || nxt > 1000) continue;
                        if (!visited[idx(nxt)]) {
                            visited[idx(nxt)] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
