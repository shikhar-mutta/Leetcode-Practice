// Link: https://leetcode.com/problems/the-kth-factor-of-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k--;
                if (k == 0) return i;
            }
        }
        return -1;
    }
};
