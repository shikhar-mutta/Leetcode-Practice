// Link: https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        if (n == 1) return 0;
        int period = 2 * (n - 1);
        int pos = k % period;
        return pos < n ? pos : period - pos;
    }
};
