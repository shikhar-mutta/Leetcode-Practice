// Link: https://leetcode.com/problems/k-items-with-the-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ones = min(k, numOnes);
        k -= ones;
        int zeros = min(k, numZeros);
        k -= zeros;
        int negOnes = k;
        return ones - negOnes;
    }
};
