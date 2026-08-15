// Link: https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: each adjacent differing pair (i-1,i) must be eliminated by some
// invert operation, and the cheapest way to flip across that boundary is
// either a prefix invert of cost i or a suffix invert of cost n-i — these two
// choices per boundary are independent of each other, so summing min(i,n-i)
// over every differing boundary gives the optimal total cost.
class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0;
        int n=s.length();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+=min(i,n-i);
            }
        }
        return ans;
    }
};
