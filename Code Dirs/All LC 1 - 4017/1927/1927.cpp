// Link: https://leetcode.com/problems/sum-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int sumL = 0, sumR = 0, qL = 0, qR = 0;
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') qL++;
            else sumL += num[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') qR++;
            else sumR += num[i] - '0';
        }
        int q = qL + qR;
        if (q % 2 == 1) return true;
        return sumL - sumR != (qR - qL) / 2 * 9;
    }
};
