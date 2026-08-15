// Link: https://leetcode.com/problems/remove-9/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: the n-th number without any digit 9 corresponds to writing n in base 9 (digits 0-8), since skipping all numbers containing a 9 is equivalent to counting in base 9.
class Solution {
public:
    int newInteger(int n) {
        long long result = 0;
        long long place = 1;
        while (n > 0) {
            result += (n % 9) * place;
            n /= 9;
            place *= 10;
        }
        return (int)result;
    }
};
