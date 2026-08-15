// Link: https://leetcode.com/problems/number-of-digit-one/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: for each digit position, count how many numbers in [1,n] have a '1' at that position,
// split into high/cur/low parts around the position
class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        for (long long place = 1; place <= n; place *= 10) {
            long long high = n / (place * 10);
            long long cur = (n / place) % 10;
            long long low = n % place;
            if (cur == 0) count += high * place;
            else if (cur == 1) count += high * place + low + 1;
            else count += (high + 1) * place;
        }
        return (int)count;
    }
};
