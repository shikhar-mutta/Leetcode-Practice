// Link: https://leetcode.com/problems/mirror-reflection/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        long long g = __gcd(p, q);
        long long m = p / g, n = q / g;
        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (m % 2 == 0) return 2;
        return 0;
    }
};
