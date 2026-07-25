// Link: https://leetcode.com/problems/count-operations-to-obtain-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(num1, num2)))
// SC: O(1)
// Approach: repeatedly subtracting the smaller from the larger num1/num2
// times in a row is equivalent to one division step, so fast-forward each
// run via num1/num2 (or num2/num1) operations and a modulo in one shot,
// mirroring the Euclidean algorithm, until either reaches 0.
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                ops += num1 / num2;
                num1 %= num2;
            } else {
                ops += num2 / num1;
                num2 %= num1;
            }
        }
        return ops;
    }
};
