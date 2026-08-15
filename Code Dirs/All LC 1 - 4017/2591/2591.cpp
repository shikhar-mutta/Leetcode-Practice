// Link: https://leetcode.com/problems/distribute-money-to-maximum-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        long long totalExtra = money - children;
        if (totalExtra < 0) return -1;

        int maxK = min((long long)children, totalExtra / 7);
        for (int k = maxK; k >= 0; k--) {
            long long remaining = totalExtra - 7LL * k;
            int freeChildren = children - k;
            if (freeChildren == 0) {
                if (remaining == 0) return k;
            } else if (freeChildren == 1) {
                if (remaining != 3) return k;
            } else {
                return k;
            }
        }
        return -1;
    }
};
