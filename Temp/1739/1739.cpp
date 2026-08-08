// Link: https://leetcode.com/problems/building-boxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        long long total = 0, base = 0;
        for (long long i = 1; ; i++) {
            if (total + i * (i + 1) / 2 > n) break;
            total += i * (i + 1) / 2;
            base = i;
        }
        long long remainder = n - total;
        long long extraBase = 0;
        while (remainder > 0) {
            extraBase++;
            remainder -= extraBase;
        }
        return (int)(base * (base + 1) / 2 + extraBase);
    }
};
