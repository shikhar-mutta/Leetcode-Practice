// Link: https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: take 1..min(n,k/2) first (none of these can pair with another to
// sum to k, since both would have to be < k/2 which forces duplicates or
// values >= k/2). Once that range is exhausted, remaining elements must be
// taken from k, k+1, k+2, ... (each >= k, so no two ever sum to exactly k
// since the smallest such value is already >= k and pairing needs two values
// summing to k, impossible once one alone is >= k unless the other is <= 0).
class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        for(int i=1; i<=min(n, k/2); i++) ans+= i;
        int rem = n - min(n, k/2);
        for(int i=0; i<rem; i++) ans += (k+i);
        return ans;
    }
};
