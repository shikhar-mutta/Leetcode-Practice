// Link: https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        // approach 1: Recursion
        int last = 1, secLast = 0, cur;
        if (n < 2)
            return n;
        for (int i = 2; i <= n; i++) {
            cur = last + secLast;
            secLast = last;
            last = cur;
        }
        return cur;
    }
};