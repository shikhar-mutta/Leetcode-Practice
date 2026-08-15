// Link: https://leetcode.com/problems/happy-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per step, cycle detected quickly  SC: O(1)
// Approach: Floyd's cycle detection (slow/fast) over the sum-of-squared-digits sequence
class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int x) {
            int sum = 0;
            while (x > 0) { int d = x % 10; sum += d * d; x /= 10; }
            return sum;
        };
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};
