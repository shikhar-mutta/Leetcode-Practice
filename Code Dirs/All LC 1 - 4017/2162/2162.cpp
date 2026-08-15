// Link: https://leetcode.com/problems/minimum-cost-to-set-cooking-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cost(int m, int s, int startAt, int moveCost, int pushCost) {
        vector<int> seq;
        if (m > 0) {
            string ms = to_string(m);
            for (char c : ms) seq.push_back(c - '0');
            string ss = to_string(s);
            while (ss.size() < 2) ss = "0" + ss;
            for (char c : ss) seq.push_back(c - '0');
        } else {
            string ss = to_string(s);
            for (char c : ss) seq.push_back(c - '0');
        }
        int total = pushCost * (int)seq.size();
        int prev = startAt;
        for (int d : seq) {
            if (d != prev) total += moveCost;
            prev = d;
        }
        return total;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int best = INT_MAX;
        int m1 = targetSeconds / 60, s1 = targetSeconds % 60;
        if (m1 <= 99) best = min(best, cost(m1, s1, startAt, moveCost, pushCost));
        if (m1 > 0) {
            int m2 = m1 - 1, s2 = s1 + 60;
            if (m2 <= 99 && s2 <= 99) best = min(best, cost(m2, s2, startAt, moveCost, pushCost));
        }
        return best;
    }
};
