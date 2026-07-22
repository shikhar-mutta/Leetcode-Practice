// Link: https://leetcode.com/problems/k-th-symbol-in-grammar/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //   1. The k-th symbol in the n-th row can be determined by recursively finding the parent symbol in the (n-1)-th row.
    //   2. If k is odd, the k-th symbol is the same as its parent symbol. If k is even, the k-th symbol is the complement of its parent symbol.
    //   3. The base case is when n=1, where the only symbol is 0.
    //   4. The recursive function continues until it reaches the base case, and the final result is returned.
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        return (k % 2 == 1) ? parent : 1 - parent;
    }
};
