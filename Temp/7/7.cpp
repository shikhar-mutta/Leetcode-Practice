// Link: https://leetcode.com/problems/reverse-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log10(x))  SC: O(1)
// Approach: pop digits from x, push into result using long long, then check int overflow at the end
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return (int)res;
    }
};
