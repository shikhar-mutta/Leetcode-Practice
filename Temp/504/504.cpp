// Link: https://leetcode.com/problems/base-7/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: repeated division by 7, handle sign separately
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        long long n = abs((long long)num);
        string res;
        while (n) {
            res += char('0' + n % 7);
            n /= 7;
        }
        if (neg) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};
