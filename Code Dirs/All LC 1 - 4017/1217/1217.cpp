// Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int p : position) {
            if (p % 2 == 0) even++;
            else odd++;
        }
        return min(odd, even);
    }
};
