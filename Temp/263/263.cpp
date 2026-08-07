// Link: https://leetcode.com/problems/ugly-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: repeatedly divide out factors of 2, 3, and 5; ugly iff we end at 1
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int p : {2, 3, 5}) {
            while (n % p == 0) n /= p;
        }
        return n == 1;
    }
};
