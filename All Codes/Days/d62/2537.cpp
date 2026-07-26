// Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: sliding window tracking the number of equal-value pairs
// inside it. Adding nums[i] contributes its current occurrence count as
// new pairs (mpp[nums[i]]++, decrementing the remaining k needed).
// Shrink from the left while k has dropped to 0 or below (window already
// has >= k pairs), since every valid left boundary at or before the
// current `left` also forms a good subarray ending at i — that's why
// `left` itself (the count of valid start positions) is added each step.
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long cnt=0;
        for(int i=0,left=0;i<nums.size();i++){
            k-=mpp[nums[i]]++;
            while(k<=0) k+=--mpp[nums[left++]];
            cnt+=left;

        }
        return cnt;
    }
};
