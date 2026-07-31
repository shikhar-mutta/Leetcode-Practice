// Link: https://leetcode.com/problems/find-the-least-frequent-digit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int cnt[10] = {0};
        while (n > 0) { cnt[n % 10]++; n /= 10; }
        int best = -1;
        for (int d = 0; d < 10; d++) {
            if (cnt[d] > 0 && (best == -1 || cnt[d] < cnt[best])) best = d;
        }
        return best;
    }
};
