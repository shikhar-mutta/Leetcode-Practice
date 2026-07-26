// Link: https://leetcode.com/problems/alternating-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits(n))
// SC: O(digits(n)) for the string conversion
// Approach: walk n's digits from most to least significant, alternating
// the sign starting with + for the first digit, summing as we go.
class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0, sign = 1;
        // process digits from most significant to least
        string s = to_string(n);
        for (char c : s) {
            sum += sign * (c - '0');
            sign = -sign;
        }
        return sum;
    }
};
