// Link: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};
        while (fib.back() < k) fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);

        int count = 0;
        int i = fib.size() - 1;
        while (k > 0) {
            while (fib[i] > k) i--;
            k -= fib[i];
            count++;
        }
        return count;
    }
};
