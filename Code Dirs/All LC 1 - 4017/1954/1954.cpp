// Link: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long lo = 1, hi = 100000;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long total = 2 * mid * (mid + 1) * (2 * mid + 1);
            if (total >= neededApples) hi = mid;
            else lo = mid + 1;
        }
        return 8 * lo;
    }
};
