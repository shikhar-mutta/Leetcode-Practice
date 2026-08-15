// Link: https://leetcode.com/problems/integer-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: if even halve it; if odd, choose +1 or -1 based on the second
// bit (special-case 3 to go down) to minimize trailing operations
class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int steps = 0;
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num == 3 || (num & 3) == 1) {
                num -= 1;
            } else {
                num += 1;
            }
            steps++;
        }
        return steps;
    }
};
