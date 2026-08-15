// Link: https://leetcode.com/problems/nth-digit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: determine digit-length group n falls in, then find the exact
// number and digit within it
class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1, count = 9, start = 1;
        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        long long num = start + (n - 1) / digits;
        int digitIdx = (n - 1) % digits;
        string s = to_string(num);
        return s[digitIdx] - '0';
    }
};
