// Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(max value) for the last-seen-index hash array (values <= 1e5)
// Approach: sliding window of size k tracking a running sum, using a
// last-seen-index array to detect duplicates. When the incoming element
// was already seen inside the current window, shrink from the left past
// its previous occurrence (clearing those indices from the hash) before
// including it. Once the window reaches size k, record the max sum and
// slide it forward by one.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0;
        long long sum = 0, maxsum = 0;
        int n = nums.size();
        int i;
        int hash[100001];
        for(int i = 0 ;i < 100001; i++){
            hash[i] = -1;
        }
        while(r < n){

            if(hash[nums[r]] != -1){
                i = l;
                l = hash[nums[r]] + 1;
                while(i < l){
                    sum = sum - nums[i];
                    hash[nums[i]] = -1;
                    i++;
                    count--;
                }
            }

            sum = sum + nums[r];
            hash[nums[r]] = r;
            count = count + 1;
            if(count == k){
                maxsum = max(sum , maxsum);
                sum = sum - nums[l];
                hash[nums[l]] = -1;
                l++;
                count = count - 1;
            }
            r++;
        }
        return maxsum;
    }
};
