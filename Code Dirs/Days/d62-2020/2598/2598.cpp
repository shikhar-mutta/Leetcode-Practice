// Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + result) — result is bounded by n since each residue bucket has at
// most n/value elements and we consume one per step
// SC: O(value)
// Approach: adding/subtracting `value` to an element only changes it within its
// residue class mod value, so each element can be "morphed" into any number
// sharing its residue. Bucket elements by ((nums[i]%value)+value)%value count,
// then greedily find the mex: for candidate mex starting at 0, if its residue
// bucket still has an unused element, consume one and advance; otherwise that's
// the answer since the bucket can't supply this value.
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> MEX(value+1,0);
        for(int i=0;i<nums.size();i++){
            int MOD = (nums[i]%value + value) %value;
            MEX[MOD]++;
        }

        int mex =0;
        while(true){
            int rem = mex % value;
            if(MEX[rem]==0) return mex;

            MEX[rem]--;

            mex++;

        }
        return mex;
    }
};
