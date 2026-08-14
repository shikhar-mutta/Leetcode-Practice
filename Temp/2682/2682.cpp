// Link: https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> received(n, false);
        int cur = 0, step = 1;
        while (!received[cur]) {
            received[cur] = true;
            cur = (cur + step * k) % n;
            step++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) if (!received[i]) ans.push_back(i + 1);
        return ans;
    }
};
