// Link: https://leetcode.com/problems/next-greater-numerically-balanced-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(int x) {
        int cnt[10] = {0};
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; d++) {
            if (cnt[d] != 0 && cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (!isBalanced(x)) x++;
        return x;
    }
};
