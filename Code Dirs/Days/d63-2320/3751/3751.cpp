// Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((num2-num1) * log(num2)) SC: O(log(num2))
// Approach: brute force each number in range, extract its digits, and
// count interior positions that are strictly greater or strictly less
// than both neighbors.
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int x = num1; x <= num2; x++) {
            string s = to_string(x);
            int n = s.size();
            for (int i = 1; i + 1 < n; i++) {
                int a = s[i-1] - '0', b = s[i] - '0', c = s[i+1] - '0';
                if ((b > a && b > c) || (b < a && b < c)) total++;
            }
        }
        return total;
    }
};
