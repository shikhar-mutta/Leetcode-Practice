// Link: https://leetcode.com/problems/number-of-common-factors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int count = 0;
        for (int i = 1; i <= g; i++)
            if (g % i == 0) count++;
        return count;
    }
};
