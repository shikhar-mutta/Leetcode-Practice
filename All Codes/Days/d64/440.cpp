// Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(n)^2)  SC: O(1)
// Approach: walk a virtual lexicographical trie of numbers 1..n. At each
// step count how many numbers fall in the subtree rooted at the current
// prefix; if that count <= k, skip the whole subtree (move to next
// sibling), otherwise descend into the subtree (multiply prefix by 10).
class Solution {
    long long countSteps(long long prefix, long long n) {
        long long steps = 0;
        long long first = prefix, last = prefix;
        while (first <= n) {
            steps += min(n, last) - first + 1;
            first *= 10;
            last = last * 10 + 9;
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
                k -= steps;
                cur++;
            } else {
                cur *= 10;
                k--;
            }
        }
        return (int)cur;
    }
};
