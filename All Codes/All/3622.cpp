// Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int x = n;
        while (x > 0) {
            sum += x % 10;
            prod *= x % 10;
            x /= 10;
        }
        return n % (sum + prod) == 0;
    }
};
