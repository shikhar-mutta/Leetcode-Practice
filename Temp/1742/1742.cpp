// Link: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> cnt;
        int best = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int s = 0, x = i;
            while (x > 0) { s += x % 10; x /= 10; }
            best = max(best, ++cnt[s]);
        }
        return best;
    }
};
