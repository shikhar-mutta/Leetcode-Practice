// Link: https://leetcode.com/problems/number-of-valid-clock-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTime(string time) {
        int count = 0;
        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {
                char buf[6];
                snprintf(buf, sizeof(buf), "%02d:%02d", h, m);
                bool ok = true;
                for (int i = 0; i < 5; i++)
                    if (time[i] != '?' && time[i] != buf[i]) ok = false;
                if (ok) count++;
            }
        }
        return count;
    }
};
