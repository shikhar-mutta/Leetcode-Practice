// Link: https://leetcode.com/problems/maximum-product-of-two-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n) {
            int d = n % 10;
            if (d >= first) {
                second = first;
                first = d;
            } else if (d > second)
                second = d;
            n /= 10;
        }
        return first * second;
    }
};