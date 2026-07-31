// Link: https://leetcode.com/problems/two-letter-card-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int score(vector<string>& cards, char x) {
        int xxCount = 0;
        vector<int> xGroup(26, 0), groupX(26, 0); // x_ type grouped by 2nd letter, _x type grouped by 1st letter

        for (auto& c : cards) {
            bool has0 = (c[0] == x), has1 = (c[1] == x);
            if (!has0 && !has1) continue;
            if (has0 && has1) xxCount++;
            else if (has0) xGroup[c[1] - 'a']++;
            else groupX[c[0] - 'a']++;
        }

        int sumA = 0, maxA = 0;
        for (int g : xGroup) { sumA += g; maxA = max(maxA, g); }
        int sumB = 0, maxB = 0;
        for (int g : groupX) { sumB += g; maxB = max(maxB, g); }

        auto matchWithVirtual = [](int sumReal, int maxReal, int t) -> int {
            int total = sumReal + t;
            int maxClass = max(maxReal, t);
            return min(total / 2, total - maxClass);
        };

        int best = 0;
        for (int tA = 0; tA <= xxCount; tA++) {
            int tB = xxCount - tA;
            int total = matchWithVirtual(sumA, maxA, tA) + matchWithVirtual(sumB, maxB, tB);
            best = max(best, total);
        }
        return best;
    }
};
