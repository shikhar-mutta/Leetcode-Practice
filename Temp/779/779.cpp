// Link: https://leetcode.com/problems/k-th-symbol-in-grammar/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log k) SC: O(1)
// Approach: (k-1) in binary encodes the path from root; the value at each level flips based on the parent's parity and the current bit — equivalently the answer is the parity (popcount) of k-1.
class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k-1) % 2;
    }
};
