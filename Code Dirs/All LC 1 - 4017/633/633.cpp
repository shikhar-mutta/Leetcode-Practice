// Link: https://leetcode.com/problems/sum-of-square-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(c)) SC: O(1)
// Approach: two pointers a=0, b=sqrt(c); adjust based on a*a+b*b vs c.
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = (long long)sqrt(c);
        while (a <= b) {
            long long sum = a*a + b*b;
            if (sum == c) return true;
            if (sum < c) a++;
            else b--;
        }
        return false;
    }
};
