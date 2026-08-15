// Link: https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int limit = (int)sqrt((double)r) + 2;
        vector<bool> isComposite(limit + 1, false);
        for (int i = 2; (long long)i * i <= limit; i++) {
            if (!isComposite[i]) {
                for (long long j = (long long)i * i; j <= limit; j += i)
                    isComposite[j] = true;
            }
        }
        int specialCount = 0;
        for (int p = 2; p <= limit; p++) {
            if (!isComposite[p]) {
                long long sq = (long long)p * p;
                if (sq >= l && sq <= r) specialCount++;
            }
        }
        return (r - l + 1) - specialCount;
    }
};
