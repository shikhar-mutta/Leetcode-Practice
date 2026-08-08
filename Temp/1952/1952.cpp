// Link: https://leetcode.com/problems/three-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) count++;
        }
        return count == 3;
    }
};
