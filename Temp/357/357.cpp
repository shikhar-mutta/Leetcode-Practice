// Link: https://leetcode.com/problems/count-numbers-with-unique-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: count = 1 (for 0) + sum over lengths 1..n of unique-digit
// permutations: 9 * 9 * 8 * ... choices
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int total = 10;
        int choices = 9;
        int avail = 9;
        for (int len = 2; len <= n && avail > 0; len++) {
            choices *= avail;
            total += choices;
            avail--;
        }
        return total;
    }
};
