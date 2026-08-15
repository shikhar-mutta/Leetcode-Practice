// Link: https://leetcode.com/problems/perfect-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n))  SC: O(1)
// Approach: sum divisors up to sqrt(num), pairing i with num/i
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = 2; (long long)i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) sum += num / i;
            }
        }
        return sum == num;
    }
};
