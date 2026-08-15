// Link: https://leetcode.com/problems/n-th-tribonacci-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        long long a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            long long d = a + b + c;
            a = b; b = c; c = d;
        }
        return (int)c;
    }
};
