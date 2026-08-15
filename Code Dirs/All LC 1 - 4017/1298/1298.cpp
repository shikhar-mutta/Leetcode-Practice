// Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> haveBox(n, false), used(n, false);
        vector<int> curStatus = status;
        queue<int> q;
        for (int b : initialBoxes) {
            haveBox[b] = true;
            q.push(b);
        }

        int total = 0;
        bool progress = true;
        while (progress) {
            progress = false;
            queue<int> next;
            while (!q.empty()) {
                int b = q.front(); q.pop();
                if (used[b]) continue;
                if (curStatus[b] == 1) {
                    used[b] = true;
                    total += candies[b];
                    progress = true;
                    for (int k : keys[b]) curStatus[k] = 1;
                    for (int cb : containedBoxes[b]) {
                        haveBox[cb] = true;
                        next.push(cb);
                    }
                } else {
                    next.push(b);
                }
            }
            q = next;
        }
        return total;
    }
};
