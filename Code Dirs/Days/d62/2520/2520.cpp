// Link: https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits(num))
// SC: O(1)
// Approach: peel off each digit of num and check whether it evenly
// divides the original number, counting how many do.
class Solution {
public:
    int countDigits(int num) {
        int count = 0, t = num;
        while (t) {
            int d = t % 10;
            if (num % d == 0)
                ++count;
            t /= 10;
        }
        return count;
    }
};
