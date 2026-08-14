// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for (char c : customers) if (c == 'Y') totalY++;

        int penalty = totalY;
        int bestHour = 0;
        int yCount = 0, nCount = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') yCount++;
            else nCount++;
            int curPenalty = nCount + (totalY - yCount);
            if (curPenalty < penalty) {
                penalty = curPenalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};
