// Link: https://leetcode.com/problems/harshad-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log x) (one pass over the digits of x)
// SC: O(1)
// Approach: sum the digits of x, then x is a Harshad number iff it's
// divisible by that digit sum; return the sum if so, else -1.
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, t = x;
        while (t) {
            sum += t % 10;
            t /= 10;
        }
        return x % sum == 0 ? sum : -1;
    }
};
