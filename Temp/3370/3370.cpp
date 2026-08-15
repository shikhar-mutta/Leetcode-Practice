// Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) x = x * 2 + 1;
        return x;
    }
};
