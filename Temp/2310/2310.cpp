// Link: https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int n = 1; n <= 10; n++) {
            if ((n * k) % 10 == num % 10 && (long long)n * k <= num) return n;
        }
        return -1;
    }
};
