// Link: https://leetcode.com/problems/dota2-senate/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: two queues of indices for R and D; repeatedly compare front indices, the earlier one bans the later (removes it), and the survivor re-enters the queue with index+n (to preserve relative order for the next round).
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while (!r.empty() && !d.empty()) {
            int ri = r.front(), di = d.front();
            r.pop(); d.pop();
            if (ri < di) r.push(ri + n);
            else d.push(di + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};
