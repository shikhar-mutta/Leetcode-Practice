// Link: https://leetcode.com/problems/minimum-cost-good-caption/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minCostGoodCaption(string caption) {
        int n = caption.size();
        if (n < 3) return "";

        const int INF = 1e9;
        string s = caption;

        vector<int> newCost(n + 1, INF);
        vector<array<int, 26>> cont1(n + 1), cont2(n + 1), closedCost(n + 1);

        newCost[n] = 0;
        cont1[n].fill(INF);
        cont2[n].fill(INF);
        closedCost[n].fill(0);

        for (int i = n - 1; i >= 0; i--) {
            array<int, 26> cost;
            for (int c = 0; c < 26; c++)
                cost[c] = abs((s[i] - 'a') - c);

            for (int c = 0; c < 26; c++)
                cont1[i][c] = cost[c] + cont2[i + 1][c];
            for (int c = 0; c < 26; c++)
                cont2[i][c] = cost[c] + closedCost[i + 1][c];

            int best = INF;
            for (int c = 0; c < 26; c++)
                best = min(best, cost[c] + cont1[i + 1][c]);
            newCost[i] = best;

            for (int c = 0; c < 26; c++) {
                closedCost[i][c] =
                    min(cost[c] + closedCost[i + 1][c], newCost[i]);
            }
        }

        auto findNewChoice = [&](int i) -> int {
            for (int c = 0; c < 26; c++) {
                int costc = abs((s[i] - 'a') - c);
                if (costc + cont1[i + 1][c] == newCost[i])
                    return c;
            }
            return -1;
        };

        string result(n, 'a');
        int pos = 0, state = 0, curC = -1;

        while (pos < n) {
            if (state == 0) {
                int c = findNewChoice(pos);
                result[pos] = 'a' + c;
                curC = c;
                pos++;
                state = 1;
            } else if (state == 1) {
                result[pos] = 'a' + curC;
                pos++;
                state = 2;
            } else if (state == 2) {
                result[pos] = 'a' + curC;
                pos++;
                state = 3;
            } else {
                int costc = abs((s[pos] - 'a') - curC);
                int extendVal = costc + closedCost[pos + 1][curC];
                int newVal = newCost[pos];
                int target = min(extendVal, newVal);

                int chosenChar = -1;
                bool extend = false;
                if (extendVal == target) {
                    chosenChar = curC;
                    extend = true;
                }
                if (newVal == target) {
                    int nc = findNewChoice(pos);
                    if (chosenChar == -1 || nc < chosenChar) {
                        chosenChar = nc;
                        extend = false;
                    }
                }

                if (extend) {
                    result[pos] = 'a' + curC;
                    pos++;
                } else {
                    result[pos] = 'a' + chosenChar;
                    curC = chosenChar;
                    pos++;
                    state = 1;
                }
            }
        }

        return result;
    }
};
