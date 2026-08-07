// Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n * log n)  SC: O(1)
// Approach: treat numbers as a lexicographic 10-ary trie; count how many
// numbers <= n fall under a given prefix, step into subtree or move to
// next sibling accordingly
class Solution {
    long long countSteps(long long prefix, long long n) {
        long long steps = 0;
        long long cur = prefix, next = prefix + 1;
        while (cur <= n) {
            steps += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;
        while (k > 0) {
            long long steps = countSteps(cur, n);
            if (steps <= k) {
                cur++;
                k -= steps;
            } else {
                cur *= 10;
                k--;
            }
        }
        return (int)cur;
    }
};
