// Link: https://leetcode.com/problems/minimum-cost-to-set-cooking-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: a target can be displayed as (mins, secs) or, if secs was
// reduced by borrowing 60 from a minute, (mins-1, secs+60) - only these two
// representations are ever worth considering since fewer minutes just means
// more seconds instead. For each valid (0-99 range) representation, cost
// the button presses: one pushCost per digit typed (leading zero digits are
// skipped since to_string drops them), plus a moveCost every time the
// finger has to move to a different digit than the previous button press.
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost,
                       int targetSeconds) {
        int best = INT_MAX;
        int mins = targetSeconds / 60, secs = targetSeconds % 60;

        // two representations: (mins, secs) and (mins-1, secs+60)
        for (int m = mins; m >= mins - 1; --m) {
            int s = targetSeconds - m * 60;
            if (m < 0 || m > 99 || s < 0 || s > 99)
                continue;
            int cost = calcCost(m * 100 + s, startAt, moveCost, pushCost);
            best = min(best, cost);
        }
        return best;
    }

private:
    int calcCost(int display, int startAt, int moveCost, int pushCost) {
        // build digit sequence, skipping leading zeros
        string digits = to_string(display); // drops leading zeros naturally
        int cost = 0, prev = startAt;
        for (char c : digits) {
            int d = c - '0';
            if (d != prev) {
                cost += moveCost;
                prev = d;
            }
            cost += pushCost;
        }
        return cost;
    }
};
